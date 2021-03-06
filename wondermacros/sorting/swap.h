/* (C) Copyright 2015 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_SWAP_H
#define __W_SWAP_H

#include <wondermacros/meta/id.h>

/***
 *** Name:        W_SWAP
 *** Proto:       W_SWAP(T,a,b)
 *** Arg:         T   type name       The type of both a and b.
 *** Arg:         a   a value A value to be swapped
 *** Arg:         b   a value A value to be swapped
 *** Description: Use W_SWAP to swap the values of a and b. Neither of them can be constants.
 *** Notes:       Both a and b are evaluated twice.
 ***/
#define W_SWAP(T, a, b)     \
    do {                    \
        T W_ID(swap) = (a); \
        (a) = (b);          \
        (b) = W_ID(swap);   \
    } while (0)

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_SWAP,
    int a=1, b=2;
    W_SWAP(int, a, b);
    W_TEST_ASSERT(a == 2 && b == 1, "Swap failed");
)

#endif
