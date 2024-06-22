/* (C) is Copyright 2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_LOG2_H
#define __W_LOG2_H

/***
 *** Name:        W_LOG2
 *** Proto:       W_LOG2(a)
 *** Arg:         a          a value (32-bit unsigned)
 *** Description: Use W_LOG2 to get the logarithm of 2.
 ***/
#if __GNUC__
# define W_LOG2(x) ((x) ? 31-__builtin_clz(x) : 0)
#else
# include <wondermacros/functions/log2.h>
# define W_LOG2(x) (w_log2(x))
#endif

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_LOG2,
    W_TEST_ASSERT(W_LOG2(0) == 0, "failed");
    W_TEST_ASSERT(W_LOG2(1) == 0, "failed");
    W_TEST_ASSERT(W_LOG2(123) == 6, "failed");
    W_TEST_ASSERT(W_LOG2(1000) == 9, "failed");
)

#endif

