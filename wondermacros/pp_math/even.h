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

#ifndef __W_PP_EVEN_H
#define __W_PP_EVEN_H

#include <boost/preprocessor/arithmetic/mod.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

/***
 *** Name:        W_PP_EVEN
 *** Proto:       W_PP_EVEN(a)
 *** Arg:         a    a constant integer between 0...255
 *** Description: Use W_PP_EVEN to check whether a constant value is even at pre-processing time.
 ***/
#define W_PP_EVEN(a) BOOST_PP_EQUAL(BOOST_PP_MOD(a, 2), 0)

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_PP_EVEN,
#if W_PP_EVEN(2) == 1
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_EVEN(3) == 0
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif

