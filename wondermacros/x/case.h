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


/**/

#ifndef W_PREFIX
# define W_PREFIX
#endif

#ifndef W_POSTFIX
# define W_POSTFIX
#endif

#ifndef W_STATIC
# define W_STATIC 1
#endif

#ifndef W_NAME_INDEX
# define W_NAME_INDEX 0
#endif

#ifndef W_CODE_PREFIX
# define W_CODE_PREFIX
#endif

#ifndef W_CODE_POSTFIX
# define W_CODE_POSTFIX
#endif


#ifndef W_CODE
# define W_CODE(tag,code) code(tag);
#endif


#define W_CASE(name,code)                                                        \
    case W_CAT(W_PREFIX,name,W_POSTFIX): {                                       \
        W_CODE_PREFIX W_CODE(W_CAT(W_PREFIX,name,W_POSTFIX),code) W_CODE_POSTFIX \
    }                                                                            \
    break;


#include <wondermacros/x/code.h>

/**/
#include W_XFILE
/**/

#undef W_NAME
#undef W_NAME_INDEX
#undef W_XFILE
#undef W_PREFIX
#undef W_POSTFIX
#undef W_VALUE
#undef W_TYPE
#undef W_STATIC
#undef XMACRO
