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

#ifndef __W_ARRAY_GET_SIZE_H
#define __W_ARRAY_GET_SIZE_H

/***
 *** Name:        W_ARRAY_GET_SIZE
 *** Proto:       W_ARRAY_GET_SIZE(a)
 ***
 *** Arg:         a   A static array
 ***
 *** Description: Use W_ARRAY_GET_SIZE to obtain the allocation size of a static array.
 *** Returns:     The static allocation size of an array.
 *** Example:     'char foo[] = { 'a', 'b', 'c' }; printf("%d", W_ARRAY_GET_SIZE(foo));' prints '3'.
 ***/
#define W_ARRAY_GET_SIZE(a) \
    ((sizeof(a) / sizeof((a)[0])))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_ARRAY_GET_SIZE,
    int array[] = { 1, 2, 3, 4, 5 };
    W_TEST_ASSERT(W_ARRAY_GET_SIZE(array) == 5, "Array size");
)

#endif
