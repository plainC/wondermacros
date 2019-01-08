/* (C) Copyright 2016 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_VARIADIC_SORT_H
#define __W_VARIADIC_SORT_H

#include "wondermacros/sorting/swap.h"
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/size.hpp>

#ifndef COMPARE
# include "wondermacros/configs/compare.h"
#endif

/*
 * User defined sorting networks can be supplied by redefining SORTING_NETWORK_TYPE.
 */
#ifndef SORTING_NETWORK_TYPE
# define SORTING_NETWORK_TYPE W_SORTING_NETWORK_OPTIMAL_
#endif


/* A helpper macro for BOOST_PP_SEQ_FOR_EACH. */
#define _W_SORT_SWAP(r,T,swap)                                                            \
    if (COMPARE(BOOST_PP_SEQ_ELEM(0,swap),BOOST_PP_SEQ_ELEM(1,swap)) > 0)                 \
        W_SWAP(T,BOOST_PP_SEQ_ELEM(0,swap),BOOST_PP_SEQ_ELEM(1,swap));


/***
 *** Name:  W_VARIADIC_SORT
 *** Proto: W_VARIADIC_SORT(T,...)
 *** Arg:   T    type name
 *** Arg:   ...  variables to be sorted in-place
 *** Description: Use W_VARIADIC_SORT to sort variables (or array references etc.) in-place.
 ***              This is probably the fastest method to get the job done.
 ***              Redefine COMPARE to alter comparison method.
 *** Returns:     This is a statement macro.
 *** Notes: The maximum number of arguments depends on the number of sorting networks supplied.
 ***        Redefine SORTING_NETWORK_TYPE to supply a different set of sorting networks.
 ***        Given arguments are evaluated multiple times.
 ***        Given arguments have to be writtable as well, sorting is done in-place.
 ***
 *** Example: int a=5, b=2, c=0, d=9, e=3;
 ***          W_VARIADIC_SORT(int, a,b,c,d,e);
 ***
 ***          now a=0, b=2, c=3, d=5 and e=9.
 ***/
#define W_VARIADIC_SORT(T,...)                                                                   \
    do {                                                                                         \
        BOOST_PP_IF(BOOST_PP_GREATER(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),1), \
            BOOST_PP_SEQ_FOR_EACH(_W_SORT_SWAP,T,                                                    \
                BOOST_PP_CAT(SORTING_NETWORK_TYPE,BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)), \
        ) \
    } while (0)

#define W_SORTING_NETWORK_OPTIMAL_2(_0,_1)                                                             \
    ((_0)(_1))
#define W_SORTING_NETWORK_OPTIMAL_3(_0,_1,_2)                                                          \
    ((_1)(_2)) ((_0)(_1)) ((_1)(_2))
#define W_SORTING_NETWORK_OPTIMAL_4(_0,_1,_2,_3)                                                       \
    ((_0)(_1)) ((_2)(_3)) ((_0)(_2)) ((_1)(_3)) ((_1)(_2))
#define W_SORTING_NETWORK_OPTIMAL_5(_0,_1,_2,_3,_4)                                                    \
    ((_1)(_2)) ((_3)(_4)) ((_1)(_3)) ((_0)(_2)) ((_2)(_4)) ((_0)(_3)) ((_0)(_1)) ((_2)(_3)) ((_1)(_2))
#define W_SORTING_NETWORK_OPTIMAL_6(_0,_1,_2,_3,_4,_5)                                                 \
    ((_0)(_1)) ((_2)(_3)) ((_4)(_5)) ((_0)(_2)) ((_3)(_5)) ((_1)(_4)) ((_0)(_1))                       \
    ((_2)(_3)) ((_4)(_5)) ((_1)(_2)) ((_3)(_4)) ((_2)(_3))

#endif
