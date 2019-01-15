/* (C) Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_FOR_STRING_AS_UINT_H
#define __W_FOR_STRING_AS_UINT_H

#include <wondermacros/meta/id.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/before.h>


/***
 *** Name:        W_FOR_STRING_AS_UINT
 *** Proto:       W_FOR_STRING_AS_UINT(T,u,str)
 *** Arg:         T      an unsigned integer type name
 *** Arg:         u      a free variable name to be assigned
 *** Arg:         str    a string
 *** Description: Use W_FOR_STRING_AS_UINT to convert a string to an unsigned integer.
 *** Notes:       The string must be null terminated.
 ***              If the string is longer than the unsigned type can handle it is truncated.
 *** Example:     'W_FOR_STRING_AS_UINT(uint64_t,x,buffer) printf("%llu", x);'
 ***/

#define W_FOR_STRING_AS_UINT(T,u,str)                                \
    W_DECLARE(to_uint1, T u = 0)                                     \
    W_DECLARE(to_uint2, unsigned char W_ID(c))                       \
    W_BEFORE(to_uint3,                                               \
        for (unsigned W_ID(i) = 0; W_ID(i) < sizeof(T); W_ID(i)++) { \
            W_ID(c) = (str)[W_ID(i)];                                \
            if (!W_ID(c))                                            \
                break;                                               \
            (u) |= ((T) W_ID(c)) << (W_ID(i) << 3);                  \
        }                                                            \
    )

#endif
