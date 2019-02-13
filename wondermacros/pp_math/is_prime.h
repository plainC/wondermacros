/* (C) Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_PP_IS_PRIME_H
#define __W_PP_IS_PRIME_H

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/logical/and.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>

#include <wondermacros/pp_math/decompose.h>


/***
 *** Name:        W_PP_IS_PRIME
 *** Proto:       W_PP_IS_PRIME(n)
 *** Arg:         n    an integer between 0...255
 *** Description: Use W_PP_IS_PRIME to test if given argument is a prime number during pre-processing.
 ***/
#define W_PP_IS_PRIME(n)                                                                  \
    BOOST_PP_IF(BOOST_PP_GREATER(n,1),                                                    \
        BOOST_PP_AND(                                                                     \
            BOOST_PP_EQUAL(1,BOOST_PP_SEQ_SIZE(W_PP_DECOMPOSE(n))),                       \
            BOOST_PP_EQUAL(1,BOOST_PP_SEQ_ELEM(1,BOOST_PP_SEQ_ELEM(0,W_PP_DECOMPOSE(n)))) \
        ),                                                                                \
        0                                                                                 \
    )

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_PP_IS_PRIME,
#if W_PP_IS_PRIME(7)
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if W_PP_IS_PRIME(8)
    W_TEST_ASSERT(0, "failed");
#else
    W_TEST_ASSERT(1, "ok");
#endif
)

#endif
