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

#ifndef __W_SEQ_MAX_H
#define __W_SEQ_MAX_H

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <wondermacros/seq/sort.h>

/***
 *** Name:        W_SEQ_MAX
 *** Proto:       W_SEQ_MAX(...)
 *** Arg:         seq    a Boost pre-processor sequence of integer values (up to six values) between 0...255
 *** Description: Use W_SEQ_MAX to get the maximum  value in a given sequence at pre-processing time.
 ***/
#define W_SEQ_MAX(seq) \
    BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(seq)), W_SEQ_SORT(seq))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_SEQ_MAX,
#if W_SEQ_MAX((5)(2)(7)(77)) == 77
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
