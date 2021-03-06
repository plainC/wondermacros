/* (C) Copyright 2018 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_ARRAY_MOVE_LEFT_H
#define __W_ARRAY_MOVE_LEFT_H

#include <wondermacros/meta/id.h>

/***
 *** Name:        W_ARRAY_MOVE_LEFT
 *** Proto:       W_ARRAY_MOVE_LEFT(array,size,pos,offset)
 *** Arg:         array     a pointer to an array
 *** Arg:         size      size of the array
 *** Arg:         pos       start position (index) in the array
 *** Arg:         offset    steps to be moved
 *** Description: Use W_ARRAY_MOVE_LEFT to move items in an array to left by given offset.
 ***/
#define W_ARRAY_MOVE_LEFT(array,size,pos,offset)                             \
    do {                                                                     \
        int W_ID(elems) = (size);                                            \
        int W_ID(step) = (offset);                                           \
        for (int W_ID(i)=(pos); W_ID(i)<W_ID(elems)-W_ID(step); W_ID(i)++)   \
            (array)[W_ID(i)] = (array)[W_ID(i) + W_ID(step)];                \
    } while (0)

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_MOVE_LEFT,
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    W_ARRAY_MOVE_LEFT(a, 10, 4,3);

    int c[] = { 0, 1, 2, 3, 7, 8, 9 };
    for (int i=0; i < 7; i++)
        W_TEST_ASSERT(a[i] == c[i], "Value mismatch");
)

#endif
