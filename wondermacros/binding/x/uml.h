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
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <wondermacros/meta/cat.h>
#include <wondermacros/meta/cat_inner.h>


#ifndef CLASS
# error "Macro CLASS is not defined"
#endif


#undef _EXPAND_CLASS
#undef _PRIVATE

fontname = "Bitstream Vera Sans"
fontsize = 8

node [
    fontname = "Bitstream Vera Sans"
    fontsize = 8
    shape = "record"
]

edge [
    fontname = "Bitstream Vera Sans"
    fontsize = 8
    arrowhead = "empty"
]

CLASS [

    label = <
    {<B>CLASS</B>|
    Public:|

    /* Expand public properties. */
    <TABLE BORDER="0" ALIGN="left">
    <TR><TD></TD></TR>
# define public (1,)
# define private (0,)
# define read (1,(read only))

# define METHOD(...)
# define OVERRIDE(...)
# define VAR(P,type,...)          \
    BOOST_PP_OVERLOAD(_VAR_,__VA_ARGS__)(P,type,__VA_ARGS__)
# define _VAR_1(P,type,name)      \
    _VAR_2(P,type,name,)
# define _VAR_2(P,type,name,decl) \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),<TR><TD>+</TD><TD ALIGN="left">name</TD><TD></TD><TD>:</TD><TD ALIGN="left">type decl</TD><TD>BOOST_PP_TUPLE_ELEM(1,P)</TD></TR>)
    W_CAT_INNER(CLASS,__define)
# undef public
# undef private
# undef read
# undef VAR
# undef _VAR_1
# undef _VAR_2
# undef METHOD
# undef OVERRIDE
    /**/

    /* Expand public method interface. */
# define public 1
# define private 0
# define VAR(...)
# define OVERRIDE(C,name) <TR><TD>+</TD><TD ALIGN="left">name</TD><TD></TD><TD></TD><TD></TD><TD>(overload)</TD></TR>
# define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
# define _METHOD_1(C,P,type,name)      \
    _METHOD_2(C,P,type,name,())
# define _METHOD_2(C,P,type,name,args) \
    BOOST_PP_EXPR_IF(P,<TR><TD>+</TD><TD ALIGN="left">name</TD><TD ALIGN="left">args</TD><TD>:</TD><TD ALIGN="left">type</TD></TR>)
    W_CAT_INNER(CLASS,__define)
# undef public
# undef private
# undef METHOD
# undef VAR
# undef _METHOD_1
# undef _METHOD_2
# undef OVERRIDE
    </TABLE>|
    /**/

    /* Expand private properties. */
    Private:|

    <TABLE BORDER="0" ALIGN="left">
    <TR><TD></TD></TR>
# define public (9,)
# define private (1,)
# define read (0,(read only))

# define METHOD(...)
# define OVERRIDE(...)
# define VAR(P,type,...)          \
    BOOST_PP_OVERLOAD(_VAR_,__VA_ARGS__)(P,type,__VA_ARGS__)
# define _VAR_1(P,type,name)      \
    _VAR_2(P,type,name,)
# define _VAR_2(P,type,name,decl) \
    BOOST_PP_EXPR_IF(BOOST_PP_TUPLE_ELEM(0,P),<TR><TD>+</TD><TD ALIGN="left">name</TD><TD></TD><TD>:</TD><TD ALIGN="left">type decl</TD><TD>BOOST_PP_TUPLE_ELEM(1,P)</TD></TR>)
    W_CAT_INNER(CLASS,__define)
# undef public
# undef private
# undef read
# undef VAR
# undef _VAR_1
# undef _VAR_2
# undef METHOD
# undef OVERRIDE
    /**/

    /* Expand private method interface. */
#  define public 0
#  define private 1
#  define VAR(...)
#  define OVERRIDE(C,name)
#  define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
#  define _METHOD_1(C,P,type,name)      \
    _METHOD_2(C,P,type,name,())
#  define _METHOD_2(C,P,type,name,args) \
    BOOST_PP_EXPR_IF(P,<TR><TD>+</TD><TD ALIGN="left">name</TD><TD ALIGN="left">args</TD><TD>:</TD><TD ALIGN="left">type</TD></TR>)
    W_CAT_INNER(CLASS,__define)
#  undef public
#  undef private
#  undef VAR
#  undef METHOD
#  undef _METHOD_1
#  undef _METHOD_2
#  undef OVERRIDE
    </TABLE>
    /**/

# undef VAR
    }>
]

/* Add edges */
#ifdef SUPER
CLASS -> SUPER
#endif

#undef _EXPAND_CLASS
#undef CLASS
