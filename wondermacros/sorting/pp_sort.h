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
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <wondermacros/meta/seq_swap.h>

/***
 *** Name:        W_PP_SORT
 *** Proto:       W_PP_SORT(...)
 *** Arg:         ...    Variadic number of integer arguments (between 0 and 255) to be sorted (up to six arguments).
 *** Description: Use W_PP_SORT to sort variadic number of arguments at pre-processing time. For example, W_PP_SORT(5,2,77,0) expands to 0,2,5,77.
 ***/
#define W_PP_SORT(...) BOOST_PP_SEQ_ENUM(W_PP_SORT_SEQ(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

/***
 *** Name:        W_PP_SORT_SEQ
 *** Proto:       W_PP_SORT_SEQ(seq)
 *** Arg:         seq    a Boost pre-processor sequence to be sorted (maximum sequence length is six).
 *** Description: Use W_PP_SORT_SEQ to sort a Boost pre-processor sequence at pre-processing time. For example, W_PP_SORT_SEQ((5)(3)(0)(7)) expands to (0)(3)(5)(7).
 ***/
#define W_PP_SORT_SEQ(seq)                                            \
    BOOST_PP_CAT(_PP_SORT_,BOOST_PP_SEQ_SIZE(seq))(seq)

#define _PP_SORT_1(seq) seq

#define _PP_SORT_2(seq) _PP_SORT(seq, 0, 1)

#define _PP_SORT_3(seq) _PP_SORT(_PP_SORT(_PP_SORT(seq, 1, 2), 0, 1), 1, 2)

#define _PP_SORT_4(seq) \
    _PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(seq, 0, 1), 2, 3), 0, 2), 1, 3), 1, 2)

#define _PP_SORT_5(seq) \
    _PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(seq, 1, 2), 3, 4), 1, 3), 0, 2), 2, 4), 0, 3), 0, 1), 2, 3), 1, 2)

#define _PP_SORT_6(seq) \
   _PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(_PP_SORT(seq, 0, 1), 2, 3), 4, 5), 0, 2), 3, 5), 1, 4), 0, 1), 2, 3), 4, 5), 1, 2), 3, 4), 2, 3)

#define _PP_SORT(seq, lhs, rhs)                                 \
     BOOST_PP_IF(BOOST_PP_GREATER(BOOST_PP_SEQ_ELEM(lhs, seq),  \
                                  BOOST_PP_SEQ_ELEM(rhs, seq)), \
         W_SEQ_SWAP(seq, lhs, rhs),                             \
         seq)


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

W_TEST(W_PP_SORT_SEQ,
/* 1 */
#if BOOST_PP_SEQ_ELEM(0, W_PP_SORT_SEQ((2))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

/* 2 */
#if BOOST_PP_SEQ_ELEM(0, W_PP_SORT_SEQ((3)(2))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
#if BOOST_PP_SEQ_ELEM(1, W_PP_SORT_SEQ((3)(2))) == 3
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

/* 3 */
#if BOOST_PP_SEQ_ELEM(0, W_PP_SORT_SEQ((3)(0)(2))) == 0
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
#if BOOST_PP_SEQ_ELEM(1, W_PP_SORT_SEQ((3)(0)(2))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
#if BOOST_PP_SEQ_ELEM(2, W_PP_SORT_SEQ((3)(0)(2))) == 3
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif


/* 5 */
#if BOOST_PP_SEQ_ELEM(0, W_PP_SORT_SEQ((2)(77)(0)(4)(6))) == 0
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(1, W_PP_SORT_SEQ((2)(77)(0)(4)(6))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(2, W_PP_SORT_SEQ((2)(77)(0)(4)(6))) == 4
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(3, W_PP_SORT_SEQ((2)(77)(0)(4)(6))) == 6
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

#if BOOST_PP_SEQ_ELEM(4, W_PP_SORT_SEQ((2)(77)(0)(4)(6))) == 77
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
