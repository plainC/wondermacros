/* (C) is Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif

#ifndef TAGS
# define TAGS 0
#endif


#ifdef W_CLASS_DECLARE
extern struct W_CAT(CLASS,__class_private) W_CAT(CLASS,__class_instance);
#endif

#ifdef W_CLASS_GENERATE
struct W_CAT(CLASS,__private);
struct W_CAT(CLASS,__class_private) W_CAT(CLASS,__class_instance) = {
    .tags = { TAGS },

    .meta.name = BOOST_PP_STRINGIZE(CLASS),
    .meta.size = sizeof(struct W_CAT_INNER(CLASS,__private)),

    .free = W_CAT(CLASS,_free),

    /* Expand method interface. */
# define VAR(...)
# define OVERLOAD(C,name) \
    .name = /* kill warning */ (void*) W_CAT_INNER(C,__,name),
# define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
# define _METHOD_1(C,P,type,name)      \
    .name = W_CAT_INNER(C,__,name),
# define _METHOD_2(C,P,type,name,args) \
    .name = W_CAT_INNER(C,__,name),
    W_CAT(CLASS,__define)
# undef OVERLOAD
# undef METHOD
# undef _METHOD_1
# undef _METHOD_2
# undef VAR
};

void* W_CAT(CLASS,__class_instance_ptr) = &W_CAT(CLASS,__class_instance);

#undef TAGS

#endif
