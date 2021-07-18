/* (C) Copyright 2019,2021 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_PP_MIN_H
#define __W_PP_MIN_H

#include <wondermacros/sorting/pp_sort.h>

/***
 *** Name:        W_PP_MIN
 *** Proto:       W_PP_MIN(...)
 *** Arg:         ...    variadic number of integer arguments (up to six arguments) between 0...255
 *** Description: Use W_PP_MIN to get the minimum of value of arguments at pre-processing time.
 ***/
#define W_PP_MIN(...) BOOST_PP_SEQ_ELEM(0, W_PP_SORT_SEQ(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_PP_MIN,
#if W_PP_MIN(2,5) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_MIN(8,4) == 4
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_MIN(8,4,9) == 4
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_MIN(8,77,4,9) == 4
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_MIN(8,77,4,5,9) == 4
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_MIN(8,77,4,5,9,3) == 3
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif

