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

#ifndef __W_PP_SORT_H
#define __W_PP_SORT_H

#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <wondermacros/seq/sort.h>

/***
 *** Name:        W_PP_SORT
 *** Proto:       W_PP_SORT(...)
 *** Arg:         ...    Variadic number of integer arguments (between 0 and 255) to be sorted (up to six arguments).
 *** Description: Use W_PP_SORT to sort variadic number of arguments at pre-processing time. For example, W_PP_SORT(5,2,77,0) expands to 0,2,5,77.
 ***/
#define W_PP_SORT(...) BOOST_PP_SEQ_ENUM(W_SEQ_SORT(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_PP_SORT,
#if BOOST_PP_SEQ_ELEM(2, BOOST_PP_VARIADIC_TO_SEQ(W_PP_SORT(5, 2, 0))) == 5
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
