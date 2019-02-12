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

#ifndef __W_NUMERIC_CMP_H
#define __W_NUMERIC_CMP_H

/***
 *** Name:        W_NUMERIC_CMP_ASC
 *** Proto:       W_NUMERIC_CMP_ASC(a,b)
 *** Arg:         a   A value to be compared
 *** Arg:         b   A value to be compared
 *** Description: Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
 *** Returns:     -1, if a < b, 0 if a == b, and 1 if a > b.
 *** Notes:       Both a and b are evaluated twice.
 ***/
#define W_NUMERIC_CMP_ASC(a, b) \
    (((a) > (b)) - ((a) < (b)))

/***
 *** Name:        W_NUMERIC_CMP_DESC
 *** Proto:       W_NUMERIC_CMP_DESC(a,b)
 *** Arg:         a   A value to be compared
 *** Arg:         b   A value to be compared
 *** Description: Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
 *** Returns:     -1, if a > b, 0 if a == b, and 1 if a < b.
 *** Notes:       Both a and b are evaluated twice.
 ***/
#define W_NUMERIC_CMP_DESC(a, b) \
    (((a) < (b)) - ((a) > (b)))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_NUMERIC_CMP_ASC,
    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(1,2) == -1, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(2,2) == 0, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(2,1) == 1, "Comparison failed");

    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(1.1,2.2) == -1, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(2.2,2.2) == 0, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_ASC(2.2,1.1) == 1, "Comparison failed");
)

W_TEST(W_NUMERIC_CMP_DESC,
    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(1,2) == 1, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(2,2) == 0, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(2,1) == -1, "Comparison failed");

    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(1.1,2.2) == 1, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(2.2,2.2) == 0, "Comparison failed");
    W_TEST_ASSERT(W_NUMERIC_CMP_DESC(2.2,1.1) == -1, "Comparison failed");
)

#endif

