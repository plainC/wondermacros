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

#ifndef __W_VARIADIC_TO_REFS_H
#define __W_VARIADIC_TO_REFS_H

#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>

/***
 *** Name:        W_VARIADIC_TO_REFS
 *** Proto:       W_VARIADIC_TO_REFS(...)
 *** Arg:         ...   arguments to be converted to references
 *** Description: Use W_VARIADIC_TO_REFS to convert arguments to references. For instance, you have 'a,b,c,d' but you need '&a,&b,&c,&d'.
 ***/
#define W_VARIADIC_TO_REFS(...)                                     \
    BOOST_PP_SEQ_FOR_EACH_I(                                        \
        _W_VARIADIC_TO_REFS,                                        \
        BOOST_PP_SEQ_SIZE(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)),   \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))
#define _W_VARIADIC_TO_REFS(z,size,i,elem)                          \
    (void*) &(elem) BOOST_PP_COMMA_IF(                                      \
        BOOST_PP_NOT(BOOST_PP_EQUAL(BOOST_PP_DEC(size),i)))

#endif

