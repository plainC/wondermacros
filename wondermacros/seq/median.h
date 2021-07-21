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

#ifndef __W_SEQ_MEDIAN_H
#define __W_SEQ_MEDIAN_H

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/div.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <wondermacros/pp_math/even.h>
#include <wondermacros/seq/sort.h>


/***
 *** Name:        W_SEQ_MEDIAN
 *** Proto:       W_SEQ_MEDIAN(seq)
 *** Arg:         seq    a Boost pre-processor sequence to be sorted (maximum sequence length is six).
 *** Description: Use W_SEQ_MEDIAN to get the median of a Boost pre-processor sequence at pre-processing time.
 ***              The result is a sequence having one or two values depending on the length of the given sequence.
 ***              For even length, the result sequence has two values, the first one being always less or equal to
 ***              the second value. For example, W_SEQ_MEDIAN((5)(3)(0)(7)) expands to (3)(5). In order to change
 ***              the comparison macro, redefine W_SEQ_SORT_COMPARE before applying the macro.
 ***/
#define W_SEQ_MEDIAN(seq)                                                         \
    BOOST_PP_EXPR_IF(                                                             \
        W_PP_EVEN(BOOST_PP_SEQ_SIZE(seq)),                                        \
        (BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_DIV(BOOST_PP_SEQ_SIZE(seq), 2)), \
                           W_SEQ_SORT(seq))))                                     \
    (BOOST_PP_SEQ_ELEM(BOOST_PP_DIV(BOOST_PP_SEQ_SIZE(seq),2), W_SEQ_SORT(seq))) \


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif


W_TEST(W_SEQ_MEDIAN,
/* 3 */
#if BOOST_PP_SEQ_ELEM(0, W_SEQ_MEDIAN((3)(0)(2))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif

/* 4 */
#if BOOST_PP_SEQ_ELEM(0, W_SEQ_MEDIAN((2)(77)(0)(6))) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
#if BOOST_PP_SEQ_ELEM(1, W_SEQ_MEDIAN((2)(77)(0)(6))) == 6
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
