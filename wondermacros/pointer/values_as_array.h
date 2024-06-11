/* (C) Copyright 2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_VALUES_AS_ARRAY_H
#define __W_VALUES_AS_ARRAY_H

#include <boost/preprocessor/variadic/size.hpp>


/***
 *** Name:        W_VALUES_AS_ARRAY
 *** Proto:       W_VALUES_AS_ARRAY(T, ...)
 *** Arg:         T        element type of the array
 *** Arg:         ...      variadic number of values
 *** Description: Use W_VALUES_AS_ARRAY to get a stack reference to given values without declaring temporary variables.
 ***/
#define W_VALUES_AS_ARRAY(T, ...)                           \
    ((T[BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)]){__VA_ARGS__}) \
    /**/

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_VALUES_AS_ARRAY,
    for( int n=0; n<5; n++ )
        W_TEST_ASSERT((W_VALUES_AS_ARRAY(int, 0, 1, 2, 3, 4)[n]) == n,
                      "Value mismatch");
)

#endif

