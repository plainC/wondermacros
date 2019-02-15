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

#ifndef _W_STRINGIZE_AND_LIST_H
#define _W_STRINGIZE_AND_LIST_H

#include <boost/preprocessor/facilities/overload.hpp>

/***
 *** Name:        W_STRINGIZE_AND_LIST
 *** Proto:       W_STRINGIZE_AND_LIST(...)
 *** Arg:         ...  arguments to be converted to text and comma separated
 *** Description: Use W_STRINGIZE_AND_LIST to stringize arguments to text and comma separate them.
 ***/
#define W_STRINGIZE_AND_LIST(...) BOOST_PP_OVERLOAD(_W_STRINGIZE_LIST_,__VA_ARGS__)(__VA_ARGS__)

#define _W_STRINGIZE_LIST_1(_1)  # _1
#define _W_STRINGIZE_LIST_2(_1,_2)  # _1, # _2
#define _W_STRINGIZE_LIST_3(_1,_2,_3)  # _1, # _2, # _3
#define _W_STRINGIZE_LIST_4(_1,_2,_3,_4)  # _1, # _2, # _3, # _4
#define _W_STRINGIZE_LIST_5(_1,_2,_3,_4,_5)  # _1, # _2, # _3, # _4, # _5
#define _W_STRINGIZE_LIST_6(_1,_2,_3,_4,_5,_6)  # _1, # _2, # _3, # _4, # _5, # _6
#define _W_STRINGIZE_LIST_7(_1,_2,_3,_4,_5,_6,_7)  # _1, # _2, # _3, # _4, # _5, # _6, # _7
#define _W_STRINGIZE_LIST_8(_1,_2,_3,_4,_5,_6,_7,_8)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8
#define _W_STRINGIZE_LIST_9(_1,_2,_3,_4,_5,_6,_7,_8,_9)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9
#define _W_STRINGIZE_LIST_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10
#define _W_STRINGIZE_LIST_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11
#define _W_STRINGIZE_LIST_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11, # _12
#define _W_STRINGIZE_LIST_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11, # _12, # _13
#define _W_STRINGIZE_LIST_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11, # _12, # _13, # _14
#define _W_STRINGIZE_LIST_15(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11, # _12, # _13, # _14, # _15
#define _W_STRINGIZE_LIST_16(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16)  # _1, # _2, # _3, # _4, # _5, # _6, # _7, # _8, # _9, # _10, # _11, # _12, # _13, # _14, # _15, # _16

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif


#endif

