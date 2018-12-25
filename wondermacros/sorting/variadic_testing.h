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
 *** Name:  W_VARIADIC_IS_EQUAL
 *** Proto: W_VARIADIC_IS_EQUAL(...)
 *** Arg:   ...   elements to be tested
 *** Description: Use W_VARIADIC_IS_EQUAL to test if given values are all equal.
 ***              Expands to an expression like (a == b && b == c && ...).
 *** Returns 1 if elements are equal, 0 otherwise.
 *** Notes:  All inputs are evaluated multiple times.
 ***         Redefine COMPARE in order to change the comparison method.
 *** Example: W_VARIADIC_IS_EQUAL(1,2,3,4) evaluates to 0.
 ***/
#define W_VARIADIC_IS_EQUAL(...) \
    W_SEQ_TO_COMPARE_EXPR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), COMPARE, ==, 0, &&, 1)


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
    W_SEQ_TO_COMPARE_EXPR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), COMPARE, <=, 0, &&, 1)

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
    W_SEQ_TO_COMPARE_EXPR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), COMPARE, <, 0, &&, 1)

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
    W_SEQ_TO_COMPARE_EXPR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), COMPARE, >=, 0, &&, 1)

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
    W_SEQ_TO_COMPARE_EXPR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), COMPARE, >, 0, &&, 1)


/***
 *** Name:  W_SEQ_TO_COMPARE_EXPR
 *** Proto: W_SEQ_TO_COMPARE_EXPR(seq,method,comp_op,comp_value,log_op,neutral_value)
 *** Arg:   seq            a sequence of values to be compared
 *** Arg:   method         a function or macro name used in comparisons
 *** Arg:   comp_op        comparison operator
 *** Arg:   comp_value     comparison value
 *** Arg:   log_op         logical operator
 *** Arg:   neutral_value  neutral value
 *** Description: Use W_SEQ_TO_COMPARE_EXPR to test equality or order multiple values, for example.
 *** Returns 1 or 0.
 *** Notes:  All inputs are evaluated multiple times.
 *** Example: W_SEQ_TO_COMPARE((1)(2)(3)(4), W_NUMERIC_CMP_ASC, <=, 0, &&, 1) compares ascending order and evaluates to 1.
 *** Example: W_SEQ_TO_COMPARE((1)(2)(3)(4), W_NUMERIC_CMP_ASC, ==, 0, &&, 1) compares equality and evaluates to 0.
 ***/
#define W_SEQ_TO_COMPARE_EXPR(seq,method,comp_op,comp_value,log_op,neutral_value) \
    (BOOST_PP_SEQ_FOR_EACH_I(_W0000_HELPER,(seq,method,comp_op,comp_value,log_op),seq) neutral_value)

#define _W0000_GET_SEQ(tuple)        BOOST_PP_TUPLE_ELEM(0,tuple)
#define _W0000_GET_METHOD(tuple)     BOOST_PP_TUPLE_ELEM(1,tuple)
#define _W0000_GET_COMP_OP(tuple)    BOOST_PP_TUPLE_ELEM(2,tuple)
#define _W0000_GET_COMP_VALUE(tuple) BOOST_PP_TUPLE_ELEM(3,tuple)
#define _W0000_GET_LOG_OP(tuple)     BOOST_PP_TUPLE_ELEM(4,tuple)

#define _W0000_HELPER(z,tuple,i,elem)                                                             \
    BOOST_PP_IF(i,                                                                                \
        (_W0000_GET_METHOD(tuple)(BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(i),_W0000_GET_SEQ(tuple)), elem) \
            _W0000_GET_COMP_OP(tuple) _W0000_GET_COMP_VALUE(tuple)) _W0000_GET_LOG_OP(tuple),     \
        /* nothing */                                                                             \
    )

#endif

