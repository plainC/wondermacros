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

#ifndef __W_CHARSEQ_H
#define __W_CHARSEQ_H

#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <wondermacros/meta/id.h>
#include <wondermacros/math/min.h>

#include <string.h>


/***
 *** Name:        W_CHARSEQ_TO_STRING
 *** Proto:       W_CHARSEQ_TO_STRING(seq,buf,size)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Arg:         buf   A char buffer
 *** Arg:         size  The size of the buffer
 *** Description: Use W_CHARSEQ_TO_STRING to convert a sequence of characters to a string.
 *** Notes:       'size' is evaluated twice.
 *** Example:     'char buf[16]; W_CHARSEQ_TO_STRING( (A)(B)(C)(D), buf, 16)'
 ***/
#define W_CHARSEQ_TO_STRING(seq,buf,size)                                             \
    memcpy(buf,                                                                       \
        &((const char[]) { BOOST_PP_SEQ_FOR_EACH(_W_CHARSEQ_TO_STRING,~,seq) '\0' }), \
        W_MIN(size, (BOOST_PP_INC(BOOST_PP_SEQ_SIZE(seq)))))

#define _W_CHARSEQ_TO_STRING(z,arg,elem) W_TO_CHAR(elem),


/***
 *** Name:        W_CHARSEQ_TO_UINT
 *** Proto:       W_CHARSEQ_TO_UINT(T,seq)
 *** Arg:         T     An unsigned integer type name, e.g. unsigned or uint64_t
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_CHARSEQ_TO_UINT to convert a sequence of characters to an unsigned integer.
 *** Notes:       If the string is longer than the unsigned type can handle it is truncated.
 *** Example:     'char buf[16]; W_CHARSEQ_TO_STRING( (A)(B)(C)(D), buf, 16)'
 ***/
#define W_CHARSEQ_TO_UINT(T,seq) \
    W_CAT(_W_CHARSEQ_TO_UINT_,BOOST_PP_SEQ_SIZE(seq))(T,seq)

#define _W_CHARSEQ_TO_UINT_1(T,seq) ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(0,seq))) << 0)
#define _W_CHARSEQ_TO_UINT_2(T,seq) (_W_CHARSEQ_TO_UINT_1(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(1,seq))) << 8))
#define _W_CHARSEQ_TO_UINT_3(T,seq) (_W_CHARSEQ_TO_UINT_2(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(2,seq))) << 16))
#define _W_CHARSEQ_TO_UINT_4(T,seq) (_W_CHARSEQ_TO_UINT_3(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(3,seq))) << 24))
#define _W_CHARSEQ_TO_UINT_5(T,seq) (_W_CHARSEQ_TO_UINT_4(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(4,seq))) << 32))
#define _W_CHARSEQ_TO_UINT_6(T,seq) (_W_CHARSEQ_TO_UINT_5(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(5,seq))) << 40))
#define _W_CHARSEQ_TO_UINT_7(T,seq) (_W_CHARSEQ_TO_UINT_6(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(6,seq))) << 48))
#define _W_CHARSEQ_TO_UINT_8(T,seq) (_W_CHARSEQ_TO_UINT_7(T,seq) | ((T) (W_TO_CHAR(BOOST_PP_SEQ_ELEM(7,seq))) << 56))



/***
 *** Name:        W_CHARSEQ_TOLOWER
 *** Proto:       W_CHARSEQ_TOLOWER(seq)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_CHARSEQ_TOLOWER to convert a sequence of characters to lower case.
 *** Example:     'W_CHARSEQ_TOLOWER((R)(E)(A)(D))' expands to '(r)(e)(a)(d)'.
 ***/
#define W_CHARSEQ_TOLOWER(seq) BOOST_PP_SEQ_FOR_EACH(_W_CHARSEQ_TOLOWER,~,seq)
#define _W_CHARSEQ_TOLOWER(z,arg,elem) (W_CHAR_TOLOWER(elem))



/***
 *** Name:        W_CHARSEQ_TOUPPER
 *** Proto:       W_CHARSEQ_TOUPPER(seq)
 *** Arg:         seq   A character sequence, e.g. (R)(E)(A)(D)
 *** Description: Use W_CHARSEQ_TOUPPER to convert a sequence of characters to upper case.
 *** Example:     'W_CHARSEQ_TOUPPER((r)(a)(a)(d))' expands to '(R)(E)(A)(D)'.
 ***/
#define W_CHARSEQ_TOUPPER(seq) BOOST_PP_SEQ_FOR_EACH(_W_CHARSEQ_TOUPPER,~,seq)
#define _W_CHARSEQ_TOUPPER(z,arg,elem) (W_CHAR_TOUPPER(elem))

#endif

