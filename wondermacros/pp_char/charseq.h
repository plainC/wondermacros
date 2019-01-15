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

#ifndef __W_PP_CHARSEQ_H
#define __W_PP_CHARSEQ_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/logical/and.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

#include <wondermacros/meta/id.h>
#include <wondermacros/math/min.h>
#include <wondermacros/meta/pp_min.h>
#include <wondermacros/pp_char/to_int.h>
#include <wondermacros/pp_char/to_char.h>

#include <string.h>


/***
 *** Name:        W_PP_CHARSEQ_TO_STRING
 *** Proto:       W_PP_CHARSEQ_TO_STRING(seq,buf,size)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Arg:         buf   A char buffer
 *** Arg:         size  The size of the buffer
 *** Description: Use W_PP_CHARSEQ_TO_STRING to convert a sequence of characters to a string.
 *** Notes:       'size' is evaluated twice.
 *** Example:     'char buf[16]; W_PP_CHARSEQ_TO_STRING( (A)(B)(C)(D), buf, 16)'
 ***/
#define W_PP_CHARSEQ_TO_STRING(seq,buf,size)                                             \
    memcpy(buf,                                                                       \
        &((const char[]) { BOOST_PP_SEQ_FOR_EACH(_W_PP_CHARSEQ_TO_STRING,~,seq) '\0' }), \
        W_MIN(size, (BOOST_PP_INC(BOOST_PP_SEQ_SIZE(seq)))))

#define _W_PP_CHARSEQ_TO_STRING(z,arg,elem) W_PP_CHAR_TO_CHAR(elem),


/***
 *** Name:        W_PP_CHARSEQ_TO_UINT
 *** Proto:       W_PP_CHARSEQ_TO_UINT(T,seq)
 *** Arg:         T     An unsigned integer type name, e.g. unsigned or uint64_t
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_PP_CHARSEQ_TO_UINT to convert a sequence of characters to an unsigned integer.
 *** Notes:       If the string is longer than the unsigned type can handle it is truncated.
 *** Example:     'printf("%x", W_PP_CHARSEQ_TO_UINT(unsigned, (A)(B)(C)(D)) );'
 ***/
#define W_PP_CHARSEQ_TO_UINT(T,seq) \
    W_CAT(_W_PP_CHARSEQ_TO_UINT_,BOOST_PP_SEQ_SIZE(seq))(T,seq)

#define _W_PP_CHARSEQ_TO_UINT_1(T,seq) ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(0,seq))) << 0)
#define _W_PP_CHARSEQ_TO_UINT_2(T,seq) (_W_PP_CHARSEQ_TO_UINT_1(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(1,seq))) << 8))
#define _W_PP_CHARSEQ_TO_UINT_3(T,seq) (_W_PP_CHARSEQ_TO_UINT_2(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(2,seq))) << 16))
#define _W_PP_CHARSEQ_TO_UINT_4(T,seq) (_W_PP_CHARSEQ_TO_UINT_3(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(3,seq))) << 24))
#define _W_PP_CHARSEQ_TO_UINT_5(T,seq) (_W_PP_CHARSEQ_TO_UINT_4(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(4,seq))) << 32))
#define _W_PP_CHARSEQ_TO_UINT_6(T,seq) (_W_PP_CHARSEQ_TO_UINT_5(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(5,seq))) << 40))
#define _W_PP_CHARSEQ_TO_UINT_7(T,seq) (_W_PP_CHARSEQ_TO_UINT_6(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(6,seq))) << 48))
#define _W_PP_CHARSEQ_TO_UINT_8(T,seq) (_W_PP_CHARSEQ_TO_UINT_7(T,seq) | ((T) (W_PP_CHAR_TO_CHAR(BOOST_PP_SEQ_ELEM(7,seq))) << 56))



/***
 *** Name:        W_PP_CHARSEQ_TOLOWER
 *** Proto:       W_PP_CHARSEQ_TOLOWER(seq)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_PP_CHARSEQ_TOLOWER to convert a sequence of characters to lower case.
 *** Example:     'W_PP_CHARSEQ_TOLOWER((R)(E)(A)(D))' expands to '(r)(e)(a)(d)'.
 ***/
#define W_PP_CHARSEQ_TOLOWER(seq) BOOST_PP_SEQ_FOR_EACH(_W_PP_CHARSEQ_TOLOWER,~,seq)
#define _W_PP_CHARSEQ_TOLOWER(z,arg,elem) (W_PP_CHAR_TOLOWER(elem))



/***
 *** Name:        W_PP_CHARSEQ_TOUPPER
 *** Proto:       W_PP_CHARSEQ_TOUPPER(seq)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_PP_CHARSEQ_TOUPPER to convert a sequence of characters to upper case.
 *** Example:     'W_PP_CHARSEQ_TOUPPER((r)(a)(a)(d))' expands to '(R)(E)(A)(D)'.
 ***/
#define W_PP_CHARSEQ_TOUPPER(seq) BOOST_PP_SEQ_FOR_EACH(_W_PP_CHARSEQ_TOUPPER,~,seq)
#define _W_PP_CHARSEQ_TOUPPER(z,arg,elem) (W_PP_CHAR_TOUPPER(elem))


/***
 *** Name:        W_PP_CHARSEQ_EQUAL
 *** Proto:       W_PP_CHARSEQ_EQUAL(seq1,seq2)
 *** Arg:         seq1   A character sequence, e.g. (R)(E)(A)(D)
 *** Arg:         seq2   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_PP_CHARSEQ_EQUAL to test if two sequences of characters are equal.
 *** Example:     'W_PP_CHARSEQ_EQUAL((r)(a)(a)(d), (r)(e)(a)(d))' expands to '1'.
 ***/
#define W_PP_CHARSEQ_EQUAL(seq1,seq2)                        \
    BOOST_PP_AND(BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(seq1),  \
                                BOOST_PP_SEQ_SIZE(seq2)), \
                 _W_PP_CHARSEQ_EQUAL(seq1,seq2))


#define _W_PP_CHARSEQ_EQUAL(seq1,seq2)                       \
    BOOST_PP_CAT(_W_PP_CHARSEQ_EQUAL_,W_PP_MIN(BOOST_PP_SEQ_SIZE(seq1),BOOST_PP_SEQ_SIZE(seq2)))(seq1,seq2)

#define _W_PP_CHARSEQ_EQUAL_N(seq1,seq2,N) BOOST_PP_EQUAL(W_PP_CHAR_TO_INT(BOOST_PP_SEQ_ELEM(N,seq1)),W_PP_CHAR_TO_INT(BOOST_PP_SEQ_ELEM(N,seq2)))
#define _W_PP_CHARSEQ_EQUAL_1(seq1,seq2) _W_PP_CHARSEQ_EQUAL_N(seq1,seq2,0)
#define _W_PP_CHARSEQ_EQUAL_2(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_1(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,1))
#define _W_PP_CHARSEQ_EQUAL_3(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_2(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,2))
#define _W_PP_CHARSEQ_EQUAL_4(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_3(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,3))
#define _W_PP_CHARSEQ_EQUAL_5(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_4(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,4))
#define _W_PP_CHARSEQ_EQUAL_6(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_5(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,5))
#define _W_PP_CHARSEQ_EQUAL_7(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_6(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,6))
#define _W_PP_CHARSEQ_EQUAL_8(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_7(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,7))
#define _W_PP_CHARSEQ_EQUAL_9(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_8(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,8))
#define _W_PP_CHARSEQ_EQUAL_10(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_9(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,9))
#define _W_PP_CHARSEQ_EQUAL_11(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_10(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,10))
#define _W_PP_CHARSEQ_EQUAL_12(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_11(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,11))
#define _W_PP_CHARSEQ_EQUAL_13(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_12(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,12))
#define _W_PP_CHARSEQ_EQUAL_14(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_13(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,13))
#define _W_PP_CHARSEQ_EQUAL_15(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_14(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,14))
#define _W_PP_CHARSEQ_EQUAL_16(seq1,seq2) BOOST_PP_AND(_W_PP_CHARSEQ_EQUAL_15(seq1,seq2),_W_PP_CHARSEQ_EQUAL_N(seq1,seq2,15))

#endif
