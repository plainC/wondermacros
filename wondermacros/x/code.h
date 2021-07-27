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


#ifndef W_CODE_INDEX
# error "W_CODE_INDEX not specified"
#endif


#if W_CODE_INDEX == 0
# if W_NAME_INDEX == 0
#  define XMACRO(code,...) W_CASE(code,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(code,_0,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(code,_0,_1,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(code,_0,_1,_2,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(code,_0,_1,_2,_3,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(code,_0,_1,_2,_3,_4,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(code,_0,_1,_2,_3,_4,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 1
# if W_NAME_INDEX == 0
#  define XMACRO(name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,code,_1,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,code,_1,_2,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,code,_1,_2,_3,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,code,_1,_2,_3,_4,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,code,_1,_2,_3,_4,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 2
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,code,_2,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,code,_2,_3,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,code,_2,_3,_4,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,code,_2,_3,_4,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 3
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,_1,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,_1,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,code,_3,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,code,_3,_4,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,code,_3,_4,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 4
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,_1,_2,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,_1,_2,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,_2,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,_3,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,_3,code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,_3,code,_4,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,_3,code,_4,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 5
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,_1,_2,_3,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,_1,_2,_3,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,_2,_3,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,_3,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,_3,_4,name,code...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,_3,_4,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,_3,_4,code,name,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,_3,_4,code,_5,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 6
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,_1,_2,_3,_4,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,_1,_2,_3,_4,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,_2,_3,_4,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,_3,_4,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,_3,name,_5,code...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,_3,_4,name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,_3,_4,_5,name,...) W_CASE(name,name)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,_3,_4,_5,code,name,...) W_CASE(name,code)
# endif
#endif


#if W_CODE_INDEX == 7
# if W_NAME_INDEX == 0
#  define XMACRO(name,_0,_1,_2,_3,_4,_5,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 1
#  define XMACRO(_0,name,_1,_2,_3,_4,_5,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 2
#  define XMACRO(_0,_1,name,_2,_3,_4,_5,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 3
#  define XMACRO(_0,_1,_2,name,_3,_4,_5,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 4
#  define XMACRO(_0,_1,_2,_3,name,_5,_6,code...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 5
#  define XMACRO(_0,_1,_2,_3,_4,name,_5,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 6
#  define XMACRO(_0,_1,_2,_3,_4,_5,name,code,...) W_CASE(name,code)
# endif
# if W_NAME_INDEX == 7
#  define XMACRO(_0,_1,_2,_3,_4,_5,_6,name,...) W_CASE(name,name)
# endif
#endif
