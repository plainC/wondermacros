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
# ifndef W_XMACRO
#  error "the specification file must be specified in W_XFILE, of W_XMACRO should be defined"
# endif
#endif

#ifndef W_TYPE_INDEX
# ifndef W_TYPE
#  error "W_TYPE or W_TYPE_INDEX must be specified"
# endif
#endif


#ifndef W_PREFIX_FIELDS
# define W_PREFIX_FIELDS
#endif

#ifndef W_SUFFIX_FIELDS
# define W_SUFFIX_FIELDS
#endif


#ifndef W_PREFIX
# define W_PREFIX
#endif

#ifndef W_SUFFIX
# define W_SUFFIX
#endif

#ifndef W_NAME_INDEX
# define W_NAME_INDEX 0
#endif

#define W_FIELD(type,name) type W_CAT(W_PREFIX,name,W_SUFFIX);


/* Fixed type for all fields. */
#ifndef W_TYPE_INDEX

# if W_NAME_INDEX == 0
#  define XMACRO(name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,_3,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,_3,_4,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,_3,_4,_5,name,...) W_FIELD(W_TYPE,name)
# endif

# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,_3,_4,_5,_6,name,...) W_FIELD(W_TYPE,name)
# endif

#else

# if W_NAME_INDEX == 0
#  if W_TYPE_INDEX == 1
#   define XMACRO(name,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 2
#   define XMACRO(name,_0,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 3
#   define XMACRO(name,_0,_1,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 4
#   define XMACRO(name,_0,_1,_2,type,...) W_FIELD(type,name)
#  endif
# endif

# if W_NAME_INDEX == 1
#  if W_TYPE_INDEX == 0
#   define XMACRO(type,name,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 2
#   define XMACRO(_0,name,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 3
#   define XMACRO(_0,name,_0,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 4
#   define XMACRO(_0,name,_0,_2,type,...) W_FIELD(type,name)
#  endif
# endif

# if W_NAME_INDEX == 2
#  if W_TYPE_INDEX == 0
#   define XMACRO(type,_0,name,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 1
#   define XMACRO(_0,type,name,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 3
#   define XMACRO(_0,_1,name,type,...) W_FIELD(type,name)
#  endif
#  if W_TYPE_INDEX == 4
#   define XMACRO(_0,_1,name,_2,type,...) W_FIELD(type,name)
#  endif
# endif

#endif


struct W_NAME {
    W_PREFIX_FIELDS
#ifdef W_XFILE
# include W_XFILE
#endif
#ifdef W_XMACRO
    W_XMACRO
#endif
    W_SUFFIX_FIELDS
};

#undef W_NAME
#undef W_TYPE
#undef W_NAME_INDEX
#undef W_TYPE_INDEX
#undef W_XFILE
#undef W_PREFIX
#undef W_SUFFIX
#undef W_PREFIX_FIELDS
#undef W_SUFFIX_FIELDS
#undef W_ENUM
#undef XMACRO
