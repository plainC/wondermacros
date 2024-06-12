/* (C) Copyright 2021 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_PP_MEDIAN_H
#define __W_PP_MEDIAN_H

#include <wondermacros/seq/median.h>

/***
 *** Name:        W_PP_MEDIAN
 *** Proto:       W_PP_MEDIAN(...)
 *** Arg:         ...    variadic number of integer arguments (up to eight arguments) between 0...255
 *** Description: Use W_PP_MEDIAN to get the median of values of arguments at pre-processing time. The result is a boost sequence. If the given arguments contain even number of arguments, the result sequence has two values, the first one being less or equal to the second. For instance, W_PP_MEDIAN(5,2,7) returns (5) and W_PP_MEDIAN(7,2,4,5) returns (4)(5).
 ***/
#define W_PP_MEDIAN(...) \
    W_SEQ_MEDIAN(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_PP_MEDIAN,
#if BOOST_PP_SEQ_ELEM(0, W_PP_MEDIAN(5,2,7)) == 5
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif

