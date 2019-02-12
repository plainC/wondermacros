/* (C) is Copyright 2015,2018 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_ABS_H
#define __W_ABS_H

#ifndef W_GE
# define W_GE(a,b) ((a) >= (b))
#endif

#ifndef W_ZERO
# define W_ZERO 0
#endif

#ifndef W_NEG
# define W_NEG(a) (-(a))
#endif

/***
 *** Name:        W_ABS
 *** Proto:       W_ABS(a)
 *** Arg:         a          a value
 *** Description: Use W_ABS to get the absolute value.
 *** Notes:       Redefine W_GE, W_ZERO and W_NEG to change the default operators.
 ***/
#define W_ABS(a) (W_GE(a,W_ZERO) ? (a) : W_NEG(a))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_ABS,
    W_TEST_ASSERT(W_ABS(-1) == 1, "abs failed");
    W_TEST_ASSERT(W_ABS(1) == 1, "abs failed");
)

#endif

