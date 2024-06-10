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

#ifndef __W_IS_ANY_OF_H
#define __W_IS_ANY_OF_H


#include <boost/preprocessor/facilities/overload.hpp>


/***
 *** Name:        W_IS_ANY_OF
 *** Proto:       W_IS_ANY_OF(value,...)
 *** Arg:         value    a value to be tested
 *** Arg:         ...      variadic number of values
 *** Description: Use W_IS_ANY_OF to test if a given value is equal to any of the given other values.
 ***/
#define W_IS_ANY_OF(v, ...) BOOST_PP_OVERLOAD(W_IS_ANY_OF_, __VA_ARGS__)(v, __VA_ARGS__)
#define W_IS_ANY_OF_1(v,_0) ((v)==(_0))
#define W_IS_ANY_OF_2(v,_0,_1) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_1(v,_1))
#define W_IS_ANY_OF_3(v,_0,_1,_2) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_2(v,_1,_2))
#define W_IS_ANY_OF_4(v,_0,_1,_2,_3) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_3(v,_1,_2,_3))
#define W_IS_ANY_OF_5(v,_0,_1,_2,_3,_4) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_4(v,_1,_2,_3,_4))
#define W_IS_ANY_OF_6(v,_0,_1,_2,_3,_4,_5) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_5(v,_1,_2,_3,_4,_5))
#define W_IS_ANY_OF_7(v,_0,_1,_2,_3,_4,_5,_6) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_6(v,_1,_2,_3,_4,_5,_6))
#define W_IS_ANY_OF_8(v,_0,_1,_2,_3,_4,_5,_6,_7) (W_IS_ANY_OF_1(v,_0)||W_IS_ANY_OF_7(v,_1,_2,_3,_4,_5,_6,_7))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_IS_ANY_OF,
    W_TEST_ASSERT(W_IS_ANY_OF(3, 1, 2, 3, 4, 5),
        "Value mismatch");
    W_TEST_ASSERT(!W_IS_ANY_OF(7, 1, 3, 5, 23, 9, 2),
        "Value mismatch");
)

#endif

