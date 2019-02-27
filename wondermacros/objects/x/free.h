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
#include <wondermacros/configs/default_allocation.h>


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif

#undef _PRIVATE

#ifdef W_CLASS_GENERATE
# ifndef ABSTRACT
void W_CAT(CLASS,___finalize)(struct W_CAT(CLASS,__private)* self);
void W_CAT(CLASS,____finalize)(struct CLASS* self)
{
#  ifndef NO_DESTRUCT
    W_CAT(CLASS,___finalize)((struct W_CAT(CLASS,__private)*) self);
#  endif
}
# endif
# define _PRIVATE __private
#else /* W_CLASS_GENERATE */
void W_CAT(CLASS,____finalize)(struct CLASS* self);
#define _PRIVATE
#endif


void
W_CAT(CLASS,_free)(struct W_CAT(CLASS,__private)* self)
#ifdef W_CLASS_DECLARE
;
#endif
#ifdef W_CLASS_GENERATE
{
#ifndef ABSTRACT
#ifndef NO_DESTRUCT
    W_CAT(CLASS,___finalize)((struct W_CAT(CLASS,__private)*) self);
#endif
#endif
    W_FREE(self);
}

#endif

