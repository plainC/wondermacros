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

#ifndef __W_PP_POW2_H
#define __W_PP_POW2_H

#include <wondermacros/meta/cat.h>
#include <boost/preprocessor/cat.hpp>

#ifndef W_PP_POW2_TYPE
# define W_PP_POW2_TYPE U
#endif

/***
 *** Name:        W_PP_POW2
 *** Proto:       W_PP_POW2(i)
 *** Arg:         i    the exponent
 *** Description: Use W_PP_POW2 to get power of two for the given exponent.
 ***              The expansion is done at pre-processing time. Redefine W_PP_POW2_TYPE
 ***              to modify the numeric literal type.  The default is unsigned (U).
 ***/
#define W_PP_POW2(i) W_CAT(W_PP_POW2_,i)

#define W_PP_POW2_0 BOOST_PP_CAT(1,W_PP_POW2_TYPE)
#define W_PP_POW2_1 BOOST_PP_CAT(2,W_PP_POW2_TYPE)
#define W_PP_POW2_2 BOOST_PP_CAT(4,W_PP_POW2_TYPE)
#define W_PP_POW2_3 BOOST_PP_CAT(8,W_PP_POW2_TYPE)
#define W_PP_POW2_4 BOOST_PP_CAT(16,W_PP_POW2_TYPE)
#define W_PP_POW2_5 BOOST_PP_CAT(32,W_PP_POW2_TYPE)
#define W_PP_POW2_6 BOOST_PP_CAT(64,W_PP_POW2_TYPE)
#define W_PP_POW2_7 BOOST_PP_CAT(128,W_PP_POW2_TYPE)
#define W_PP_POW2_8 BOOST_PP_CAT(256,W_PP_POW2_TYPE)
#define W_PP_POW2_9 BOOST_PP_CAT(512,W_PP_POW2_TYPE)
#define W_PP_POW2_10 BOOST_PP_CAT(1024,W_PP_POW2_TYPE)
#define W_PP_POW2_11 BOOST_PP_CAT(2048,W_PP_POW2_TYPE)
#define W_PP_POW2_12 BOOST_PP_CAT(4096,W_PP_POW2_TYPE)
#define W_PP_POW2_13 BOOST_PP_CAT(8192,W_PP_POW2_TYPE)
#define W_PP_POW2_14 BOOST_PP_CAT(16384,W_PP_POW2_TYPE)
#define W_PP_POW2_15 BOOST_PP_CAT(32768,W_PP_POW2_TYPE)
#define W_PP_POW2_16 BOOST_PP_CAT(65536,W_PP_POW2_TYPE)
#define W_PP_POW2_17 BOOST_PP_CAT(131072,W_PP_POW2_TYPE)
#define W_PP_POW2_18 BOOST_PP_CAT(262144,W_PP_POW2_TYPE)
#define W_PP_POW2_19 BOOST_PP_CAT(524288,W_PP_POW2_TYPE)
#define W_PP_POW2_20 BOOST_PP_CAT(1048576,W_PP_POW2_TYPE)
#define W_PP_POW2_21 BOOST_PP_CAT(2097152,W_PP_POW2_TYPE)
#define W_PP_POW2_22 BOOST_PP_CAT(4194304,W_PP_POW2_TYPE)
#define W_PP_POW2_23 BOOST_PP_CAT(8388608,W_PP_POW2_TYPE)
#define W_PP_POW2_24 BOOST_PP_CAT(16777216,W_PP_POW2_TYPE)
#define W_PP_POW2_25 BOOST_PP_CAT(33554432,W_PP_POW2_TYPE)
#define W_PP_POW2_26 BOOST_PP_CAT(67108864,W_PP_POW2_TYPE)
#define W_PP_POW2_27 BOOST_PP_CAT(134217728,W_PP_POW2_TYPE)
#define W_PP_POW2_28 BOOST_PP_CAT(268435456,W_PP_POW2_TYPE)
#define W_PP_POW2_29 BOOST_PP_CAT(536870912,W_PP_POW2_TYPE)
#define W_PP_POW2_30 BOOST_PP_CAT(1073741824,W_PP_POW2_TYPE)
#define W_PP_POW2_31 BOOST_PP_CAT(2147483648,W_PP_POW2_TYPE)

#endif
