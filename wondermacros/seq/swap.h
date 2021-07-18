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

#ifndef __W_SEQ_SWAP_H
#define __W_SEQ_SWAP_H

#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/replace.hpp>

/***
 *** Name:        W_SEQ_SWAP
 *** Proto:       W_SEQ_SWAP(seq,a,b)
 *** Arg:         seq  a Boost pre-processor sequence, e.g. (1)(2)(3)
 *** Arg:         a    an index in the sequence
 *** Arg:         b    an index in the sequence
 *** Description: Use W_SEQ_SWAP to swap two positions in a Boost pre-processor sequnece.
 ***/
#define W_SEQ_SWAP(seq, a, b)                                     \
    BOOST_PP_SEQ_REPLACE(                                         \
        BOOST_PP_SEQ_REPLACE(seq, a, BOOST_PP_SEQ_ELEM(b, seq)),  \
        b, BOOST_PP_SEQ_ELEM(a, seq))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_SEQ_SWAP,
#if BOOST_PP_SEQ_ELEM(0, W_SEQ_SWAP((1)(2)(3), 0, 2)) == 3
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(1, W_SEQ_SWAP((1)(2)(3), 0, 2)) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(2, W_SEQ_SWAP((1)(2)(3), 0, 2)) == 1
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
