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

#ifndef __W_PP_POW_H
#define __W_PP_POW_H

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>


/***
 *** Name:        W_PP_POW
 *** Proto:       W_PP_POW(a,b)
 *** Arg:         a    a number between 0...255
 *** Arg:         b    an exponent between 0...31
 *** Description: Use W_PP_POW to get the power a to b. The exponent must be two or, result must be in range [0,255].
 ***/
#define W_PP_POW(a,b)                                                \
    BOOST_PP_IF(b,                                                   \
        BOOST_PP_IF(BOOST_PP_EQUAL(b,1),a,W_CAT(_W_PP_POW_,a,_,b)),  \
        0)

#define _W_PP_POW_2_2 4
#define _W_PP_POW_2_3 8
#define _W_PP_POW_2_4 16
#define _W_PP_POW_2_5 32
#define _W_PP_POW_2_6 64
#define _W_PP_POW_2_7 128
#define _W_PP_POW_2_8 256
#define _W_PP_POW_2_9 512
#define _W_PP_POW_2_10 1024
#define _W_PP_POW_2_11 2048
#define _W_PP_POW_2_12 4096
#define _W_PP_POW_2_13 8192
#define _W_PP_POW_2_14 16384
#define _W_PP_POW_2_15 32768
#define _W_PP_POW_2_16 65536
#define _W_PP_POW_2_17 131072
#define _W_PP_POW_2_18 262144
#define _W_PP_POW_2_19 524288
#define _W_PP_POW_2_20 1048576
#define _W_PP_POW_2_21 2097152
#define _W_PP_POW_2_22 4194304
#define _W_PP_POW_2_23 8388608
#define _W_PP_POW_2_24 16777216
#define _W_PP_POW_2_25 33554432
#define _W_PP_POW_2_26 67108864
#define _W_PP_POW_2_27 134217728
#define _W_PP_POW_2_28 268435456
#define _W_PP_POW_2_29 536870912
#define _W_PP_POW_2_30 1073741824
#define _W_PP_POW_2_31 2147483648

#define _W_PP_POW_3_2 9
#define _W_PP_POW_3_3 27
#define _W_PP_POW_3_4 81
#define _W_PP_POW_3_5 243

#define _W_PP_POW_5_2 25
#define _W_PP_POW_5_3 125

#define _W_PP_POW_7_2 49

#define _W_PP_POW_11_2 121
#define _W_PP_POW_13_2 169

#endif

