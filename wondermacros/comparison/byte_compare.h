/* (C) Copyright 2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_BYTE_COMPARE_H
#define __W_BYTE_COMPARE_H


#include <boost/preprocessor/facilities/overload.hpp>


/***
 *** Name:        W_BYTE_COMPARE
 *** Proto:       W_BYTE_COMPARE(buf,...)
 *** Arg:         buf      a buffer (or a string) to match
 *** Arg:         ...      variadic number of bytes (or characters)
 *** Description: Use W_BYTE_COMPARE to test if a given buffer contains given bytes. If the buffer is not \0-terminated, it must be large enough for testing.
 ***/
#define W_BYTE_COMPARE(buf, ...) \
    BOOST_PP_OVERLOAD(W_BYTE_COMPARE_, __VA_ARGS__)(buf, __VA_ARGS__)

#define W_BYTE_COMPARE_1(b, _0) ((b)[0] == (_0))
#define W_BYTE_COMPARE_2(b, _0, _1) (W_BYTE_COMPARE_1(b, _0) && ((b)[1] == (_1)))
#define W_BYTE_COMPARE_3(b, _0, _1, _2) (W_BYTE_COMPARE_2(b, _0, _1) && ((b)[2] == (_2)))
#define W_BYTE_COMPARE_4(b, _0, _1, _2, _3) (W_BYTE_COMPARE_3(b, _0, _1, _2) && ((b)[3] == (_3)))
#define W_BYTE_COMPARE_5(b, _0, _1, _2, _3, _4) (W_BYTE_COMPARE_4(b, _0, _1, _2, _3) && ((b)[4] == (_4)))
#define W_BYTE_COMPARE_6(b, _0, _1, _2, _3, _4, _5) (W_BYTE_COMPARE_5(b, _0, _1, _2, _3, _4) && ((b)[5] == (_5)))
#define W_BYTE_COMPARE_7(b, _0, _1, _2, _3, _4, _5, _6) (W_BYTE_COMPARE_6(b, _0, _1, _2, _3, _4, _5) && ((b)[6] == (_6)))
#define W_BYTE_COMPARE_8(b, _0, _1, _2, _3, _4, _5, _6, _7) (W_BYTE_COMPARE_7(b, _0, _1, _2, _3, _4, _5, _6) && ((b)[7] == (_7)))
#define W_BYTE_COMPARE_9(b, _0, _1, _2, _3, _4, _5, _6, _7, _8) (W_BYTE_COMPARE_8(b, _0, _1, _2, _3, _4, _5, _6, _7) && ((b)[8] == (_8)))
#define W_BYTE_COMPARE_10(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) (W_BYTE_COMPARE_9(b, _0, _1, _2, _3, _4, _5, _6, _7, _8) && ((b)[9] == (_9)))
#define W_BYTE_COMPARE_11(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) (W_BYTE_COMPARE_10(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) && ((b)[10] == (_10)))
#define W_BYTE_COMPARE_12(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) (W_BYTE_COMPARE_11(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) && ((b)[11] == (_11)))
#define W_BYTE_COMPARE_13(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) (W_BYTE_COMPARE_12(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) && ((b)[12] == (_12)))
#define W_BYTE_COMPARE_14(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) (W_BYTE_COMPARE_13(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) && ((b)[13] == (_13)))
#define W_BYTE_COMPARE_15(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) (W_BYTE_COMPARE_14(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) && ((b)[14] == (_14)))
#define W_BYTE_COMPARE_16(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) (W_BYTE_COMPARE_15(b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) && ((b)[15] == (_15)))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_BYTE_COMPARE,
    char* test = "comparison";

    W_TEST_ASSERT(W_BYTE_COMPARE(test, 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n'),
        "Value mismatch");
    W_TEST_ASSERT(!W_BYTE_COMPARE(test, 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', 's'),
        "Value mismatch");
)

#endif
