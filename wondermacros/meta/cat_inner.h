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

#ifndef _W_CAT_INNER__H
#define _W_CAT_INNER__H

#include <boost/preprocessor/facilities/overload.hpp>

/***
 *** Name:        W_CAT_INNER
 *** Proto:       W_CAT_INNER(...)
 *** Arg:         ...  identifiers to be concatenated
 *** Description: Use W_CAT_INNER to concatenate its arguments after they have been expanded during W_CAT expansion.
 ***              This macro is identical to W_CAT but sometimes we need to concatenate another time during W_CAT
 ***              expansion.
 ***/
#define W_CAT_INNER(...) BOOST_PP_OVERLOAD(_W_CAT_INNER_,__VA_ARGS__)(__VA_ARGS__)

#define _W_CAT_INNER_1(_1) _1
#define _W_CAT_INNER_2(_1,_2) _1 ## _2
#define _W_CAT_INNER_3(_1,_2,_3) _1 ## _2 ## _3
#define _W_CAT_INNER_4(_1,_2,_3,_4) _1 ## _2 ## _3 ## _4
#define _W_CAT_INNER_5(_1,_2,_3,_4,_5) _1 ## _2 ## _3 ## _4 ## _5
#define _W_CAT_INNER_6(_1,_2,_3,_4,_5,_6) _1 ## _2 ## _3 ## _4 ## _5 ## _6
#define _W_CAT_INNER_7(_1,_2,_3,_4,_5,_6,_7) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7
#define _W_CAT_INNER_8(_1,_2,_3,_4,_5,_6,_7,_8) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8
#define _W_CAT_INNER_9(_1,_2,_3,_4,_5,_6,_7,_8,_9) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9
#define _W_CAT_INNER_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10
#define _W_CAT_INNER_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11
#define _W_CAT_INNER_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12
#define _W_CAT_INNER_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13
#define _W_CAT_INNER_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14
#define _W_CAT_INNER_15(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15
#define _W_CAT_INNER_16(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16) _1 ## _2 ## _3 ## _4 ## _5 ## _6 ## _7 ## _8 ## _9 ## _10 ## _11 ## _12 ## _13 ## _14 ## _15 ## _16

#endif

