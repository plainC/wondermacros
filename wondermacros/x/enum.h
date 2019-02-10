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


#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>

#ifndef W_NAME
# define W_NAME
# ifndef W_PREFIX
#  define W_PREFIX
# endif
#endif

#ifndef W_XFILE
# error "the specification file must be specified in W_XFILE"
#endif

#ifndef W_PREFIX
# define W_PREFIX W_CAT_INNER(W_NAME,_)
#endif

#ifndef W_POSTFIX
# define W_POSTFIX
#endif

#ifndef W_NAME_INDEX
# define W_NAME_INDEX 0
#endif

#define W_ENUM(name) W_CAT(W_PREFIX,name,W_POSTFIX),



#if W_NAME_INDEX == 0
# define XMACRO(name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 1
# define XMACRO(_0,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 2
# define XMACRO(_0,_1,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 3
# define XMACRO(_0,_1,_2,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 4
# define XMACRO(_0,_1,_2,_3,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 5
# define XMACRO(_0,_1,_2,_3,_4,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 6
# define XMACRO(_0,_1,_2,_3,_4,_5,name,...) W_ENUM(name)
#endif

#if W_NAME_INDEX == 7
# define XMACRO(_0,_1,_2,_3,_4,_5,_6,name,...) W_ENUM(name)
#endif


enum W_NAME {
#include W_XFILE
};

#undef W_NAME
#undef W_NAME_INDEX
#undef W_XFILE
#undef W_PREFIX
#undef W_POSTFIX
#undef W_ENUM
#undef XMACRO
