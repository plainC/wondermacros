/* (C) Copyright 2017 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_BYTE_OFFSET_H
#define __W_BYTE_OFFSET_H

/***
 *** Name:        W_BYTE_OFFSET
 *** Proto:       W_BYTE_OFFSET(ptr1,ptr2)
 *** Arg:         ptr1       a pointer
 *** Arg:         ptr2       a pointer
 *** Description: Use W_BYTE_OFFSET to count the offset of two pointers. The offset is negative if ptr1 is before ptr2.
 ***/
#define W_BYTE_OFFSET(ptr1,ptr2) \
    (((char*)(ptr1)) - ((char*)(ptr2)))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_BYTE_OFFSET,
    const char* array[] = { "foo", "bar" };

    W_TEST_ASSERT(W_BYTE_OFFSET(array[0],array[1]) == -sizeof(const char*), "Invalid offset");
)

#endif

