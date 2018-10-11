/* (C) Copyright 2018 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_VARIADIC_IS_IN_ORDER_H
#define __W_VARIADIC_IS_IN_ORDER_H

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#ifndef COMPARE
# include "wondermacros/configs/compare.h"
#endif

/***
 *** Name:  W_VARIADIC_IS_IN_ASC_ORDER
 *** Proto: W_VARIADIC_IS_IN_ASC_ORDER(...)
 *** Arg:   ...   elements to be tested
 *** Description: Use W_VARIADIC_IS_IN_ASC_ORDER to test if given input is in ascending order.
 *** Returns 1 if elements are in ascending order, 0 otherwise.
 *** Notes:  All inputs are evaluated multiple times.
 ***         Redefine COMPARE in order to change the comparison method.
 *** Example: W_VARIADIC_IS_IN_ASC_ORDER(1,2,3,4) evaluates to 1.
 ***/
#define W_VARIADIC_IS_IN_ASC_ORDER(...) \
    W_SEQ_IS_IN_ORDER(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), <=)

/***
 *** Name:  W_VARIADIC_IS_IN_TOTAL_ASC_ORDER
 *** Proto: W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...)
 *** Arg:   ...   elements to be tested
 *** Description: Use W_VARIADIC_IS_IN_TOTAL_ASC_ORDER to test if given input is in total ascending order.
 *** Returns 1 if elements are in ascending order, 0 otherwise.
 *** Notes:  All inputs are evaluated multiple times.
 ***         Redefine COMPARE in order to change the comparison method.
 *** Example: W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(1,2,3,4) evaluates to 1.
 ***/
#define W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...) \
    W_SEQ_IS_IN_ORDER(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), <)

/***
 *** Name:  W_VARIADIC_IS_IN_DESC_ORDER
 *** Proto: W_VARIADIC_IS_IN_DESC_ORDER(...)
 *** Arg:   ...   elements to be tested
 *** Description: Use W_VARIADIC_IS_IN_DESC_ORDER to test if given input is in descending order.
 *** Returns 1 if elements are in descending order, 0 otherwise.
 *** Notes:  All inputs are evaluated multiple times.
 ***         Redefine COMPARE in order to change the comparison method.
 *** Example: W_VARIADIC_IS_IN_DESC_ORDER(3,3,2,1) evaluates to 1.
 ***/
#define W_VARIADIC_IS_IN_DESC_ORDER(...) \
    W_SEQ_IS_IN_ORDER(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), >=)

/***
 *** Name:  W_VARIADIC_IS_IN_TOTAL_DESC_ORDER
 *** Proto: W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...)
 *** Arg:   ...   elements to be tested
 *** Description: Use W_VARIADIC_IS_IN_TOTAL_DESC_ORDER to test if given input is in total descending order.
 *** Returns 1 if elements are in total descending order, 0 otherwise.
 *** Notes:  All inputs are evaluated multiple times.
 ***         Redefine COMPARE in order to change the comparison method.
 *** Example: W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(4,3,2,1) evaluates to 1.
 ***/
#define W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...) \
    W_SEQ_IS_IN_ORDER(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), >)


#define W_SEQ_IS_IN_ORDER(seq,op) \
    BOOST_PP_SEQ_FOR_EACH_I(_W_IS_IN_ORDER,(op,seq),seq) 1
#define _W_IS_IN_ORDER(z,tuple,i,elem) \
    BOOST_PP_IF(i,\
        (COMPARE(BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(i),BOOST_PP_TUPLE_ELEM(1,tuple) /*=seq*/), elem) \
            BOOST_PP_TUPLE_ELEM(0,tuple) /*=op*/ 0) &&, \
        /* nothing */\
    )

#endif
