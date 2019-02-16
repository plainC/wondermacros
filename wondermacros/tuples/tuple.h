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
#ifndef __W_TUPLE_H
#define __W_TUPLE_H

#include <boost/preprocessor/facilities/overload.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <string.h>


/***
 *** Name:        W_TUPLE_TYPE
 *** Proto:       W_TUPLE_TYPE(type_seq)
 *** Arg:         type_seq   a sequence of types (e.g. `(int)(double)(const char*)`
 *** Description: Use W_TUPLE_TYPE to get an anonymous struct for a tuple.
 ***/
#define W_TUPLE_TYPE(type_seq)                                   \
    struct { BOOST_PP_SEQ_FOR_EACH_I(_W_TUPLE_TYPE,~,type_seq) }
#define _W_TUPLE_TYPE(z,data,i,elem) elem _ ## i;


/***
 *** Name:        W_TUPLE_INIT
 *** Proto:       W_TUPLE_INIT(type_seq,ptr,...)
 *** Arg:         type_seq   a sequence of types (e.g. `(int)(double)(const char*)`
 *** Arg:         ptr        a pointer for writting (sizeof(W_TUPLE_TYPE(type_seq))
 *** Arg:         ...        values of the tuple
 *** Description: Use W_TUPLE_INIT to initialize a tuple.
 ***/
#define W_TUPLE_INIT(types,ptr,...)                              \
    memcpy((ptr), &(W_TUPLE_TYPE(types)) { __VA_ARGS__ },        \
        sizeof(W_TUPLE_TYPE(types)))

/***
 *** Name:        W_TUPLE_ELEM
 *** Proto:       W_TUPLE_ELEM(tuplep,ix)
 *** Arg:         tuplep     a pointer to a tuple
 *** Arg:         ix         an index of an element in the tuple
 *** Description: Use W_TUPLE_ELEM to access (read or assign) an individual element in the tuple.
 ***/
#define W_TUPLE_ELEM(tuplep,ix) ((tuplep)->_ ## ix)

#endif
