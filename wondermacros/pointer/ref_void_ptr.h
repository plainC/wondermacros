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

#ifndef __W_REF_VOID_PTR_H
#define __W_REF_VOID_PTR_H

/***
 *** Name:        W_REF_VOID_PTR
 *** Proto:       W_REF_VOID_PTR(ptr,offset)
 *** Arg:         ptr     a pointer       A pointer to be referenced by an offset.
 *** Arg:         offset  an offset       An offset in bytes.
 *** Description: Use W_REF_VOID_PTR to reference a void pointer using an offset in bytes.
 ***/
#define W_REF_VOID_PTR(ptr,offset) \
    ((void*)((char*) (ptr) + (offset)))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_REF_VOID_PTR,
    int array[] = { 1, 2, 3 };

    W_TEST_ASSERT(*((int*) W_REF_VOID_PTR(array,sizeof(int) * 1)) == 2,
        "Value mismatch");
    W_TEST_ASSERT(*((int*) W_REF_VOID_PTR(array,sizeof(int) * 2)) == 3,
        "Value mismatch");
)

#endif

