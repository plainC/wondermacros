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
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/cat.hpp>
#include <wondermacros/meta/cat.h>

#ifndef PREFIX
# define PREFIX
#endif

#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


struct W_CAT(PREFIX,CLASS,__private);

/* Declare private class struct. */
#define METHOD(type,name,args,...) \
    type (*name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));
struct W_CAT(PREFIX,CLASS,__class_private) {
    struct {
        const char* name;
        size_t size;
    } meta;
#ifdef SUPER
    W_CAT(SUPER,__public_methods)
#endif

    W_CAT(CLASS,__public_methods)
    W_CAT(CLASS,__private_methods)
};
#undef METHOD


/* Declare private instance struct. */
#define PROPERTY(type,name,...) type name;

struct W_CAT(PREFIX,CLASS,__private) {
    struct W_CAT(PREFIX,CLASS,__class_private)* klass;
#ifdef SUPER
    W_CAT(SUPER,__public_properties)
#endif

    W_CAT(CLASS,__public_properties)
    W_CAT(CLASS,__private_properties)
};

#undef PROPERTY



#ifndef ABSTRACT

/* Forward declare methods. */
#define METHOD(type,name,args,...) \
    static type BOOST_PP_CAT(__method__,name) (struct BOOST_PP_CAT(BOOST_PP_CAT(PREFIX,CLASS),__private)* self \
        BOOST_PP_REMOVE_PARENS(args));

#ifdef SUPER
W_CAT(SUPER,__public_methods)
W_CAT(SUPER,__private_methods)
#endif
W_CAT(CLASS,__public_methods)
W_CAT(CLASS,__private_methods)

#undef METHOD



/* Initialize class struct instance if not an abstract class. */

# define METHOD(type,name,args,...) \
    .name = (type (*)(struct BOOST_PP_CAT(PREFIX,CLASS)* self BOOST_PP_REMOVE_PARENS(args))) BOOST_PP_CAT(__method__,name),
struct W_CAT(PREFIX,CLASS,__class) W_CAT(PREFIX,CLASS,__class_instance) = {
    .meta.name = BOOST_PP_STRINGIZE(CLASS),
//    .meta.size = sizeof(struct W_CAT(PREFIX,CLASS,__private)),
# ifdef SUPER
    W_CAT(SUPER,__public_methods)
# endif
    W_CAT(CLASS,__public_methods)
    W_CAT(CLASS,__private_methods)
};
# undef METHOD

#endif




/* Define method macros to provide signatures. */
#define METHOD(type,name,args,...) \
static type W_CAT(__method__,name) (struct W_CAT(PREFIX,CLASS,__private)* self BOOST_PP_REMOVE_PARENS(args))


#undef ABSTRACT

