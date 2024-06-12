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
 *
 *
 * See Henry S. Warren, Jr. "Hacker's Delight', pp. 19
 */

#ifndef __W_UINT_AVERAGE_H
#define __W_UINT_AVERAGE_H

/***
 *** Name:        W_UINT_AVERAGE_FLOOR
 *** Proto:       W_UINT_AVERAGE_FLOOR(x, y)
 *** Arg:         x          an unsigned numeric value
 *** Arg:         y          an unsigned numeric value
 *** Description: Use W_UINT_AVERAGE_FLOOR to get the average (floor) of two unsigned integers without overflow or division operator.
 ***/
#define W_UINT_AVERAGE_FLOOR(x,y) (((x) & (y)) + (((x) ^ (y)) >> 1u))


/***
 *** Name:        W_UINT_AVERAGE_CEIL
 *** Proto:       W_UINT_AVERAGE_CEIL(x, y)
 *** Arg:         x          an unsigned numeric value
 *** Arg:         y          an unsigned numeric value
 *** Description: Use W_UINT_AVERAGE_CEIL to get the average (ceil) of two unsigned integers without overflow or division operator.
 ***/
#define W_UINT_AVERAGE_CEIL(x,y) (((x) | (y)) - (((x) ^ (y)) >> 1u))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_UINT_AVERAGE_FLOOR,
    W_TEST_ASSERT(W_UINT_AVERAGE_FLOOR(383, 886) == 634, "avg failed");
    W_TEST_ASSERT(W_UINT_AVERAGE_FLOOR(793, 335) == 564, "avg failed");
)

W_TEST(W_UINT_AVERAGE_CEIL,
    W_TEST_ASSERT(W_UINT_AVERAGE_CEIL(383, 886) == 635, "avg failed");
    W_TEST_ASSERT(W_UINT_AVERAGE_CEIL(793, 335) == 564, "avg failed");
)

#endif
