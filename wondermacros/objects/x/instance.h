/* (C) is Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


#undef _EXPAND_CLASS
#undef _READ_SPECIFIER


#ifdef W_FORWARD_DECLARE
struct CLASS;
#endif

#ifdef W_DECLARE
struct CLASS {
    struct W_CAT(CLASS,__class)* klass;
# define _READ_SPECIFIER const
#define _EXPAND_CLASS
#endif

#ifdef W_GENERATE
struct W_CAT(CLASS,__private) {
    struct W_CAT(CLASS,__class_private)* klass;
# define _READ_SPECIFIER
#define _EXPAND_CLASS
#endif

#ifdef _EXPAND_CLASS


    /* Expand public properties. */
# define public (1,)
# define private (0,)
# define read (1,_READ_SPECIFIER )

# define VAR(P,type,...)          \
    BOOST_PP_OVERLOAD(_VAR_,__VA_ARGS__)(P,type,__VA_ARGS__)
# define _VAR_1(P,type,name)      \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),BOOST_PP_TUPLE_ELEM(1,P) type name;)
# define _VAR_2(P,type,name,decl) \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),BOOST_PP_TUPLE_ELEM(1,P) type name decl;)
    W_CAT_INNER(CLASS,__vars)
# undef public
# undef private
# undef read
# undef VAR
# undef _VAR_1
# undef _VAR_2
    /**/


    /* Expand private properties. */
# define public (0,)
# define private (1,)
# define read (0, )

# define VAR(P,type,...)          \
    BOOST_PP_OVERLOAD(_VAR_,__VA_ARGS__)(P,type,__VA_ARGS__)
# define _VAR_1(P,type,name)      \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),BOOST_PP_TUPLE_ELEM(1,P) type name;)
# define _VAR_2(P,type,name,decl) \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),BOOST_PP_TUPLE_ELEM(1,P) type name decl;)
    W_CAT_INNER(CLASS,__vars)
# undef public
# undef private
# undef read
# undef VAR
# undef _VAR_1
# undef _VAR_2
    /**/

};
#endif

#undef _EXPAND_CLASS
#undef _READ_SPECIFIER

