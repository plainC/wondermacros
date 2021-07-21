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

#ifndef __W_SEQ_MIN_H
#define __W_SEQ_MIN_H

#include <boost/preprocessor/seq/elem.hpp>
#include <wondermacros/seq/sort.h>

/***
 *** Name:        W_SEQ_MIN
 *** Proto:       W_SEQ_MIN(...)
 *** Arg:         seq    a Boost pre-processor sequence of integer values (up to six values) between 0...255
 *** Description: Use W_SEQ_MIN to get the maximum  value in a given sequence at pre-processing time.
 ***              For example, W_SEQ_MIN((5)(2)(0)) expands to 0.
 ***/
#define W_SEQ_MIN(seq) \
    BOOST_PP_SEQ_ELEM(0, W_SEQ_SORT(seq))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_SEQ_MIN,
#if W_SEQ_MIN((5)(2)(7)(77)) == 2
    W_TEST_ASSERT(1, "ok");
#else
    W_TEST_ASSERT(0, "failed");
#endif
)

#endif
