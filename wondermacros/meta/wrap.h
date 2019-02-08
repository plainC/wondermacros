#ifndef __W_WRAP_H
#define __W_WRAP_H

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

#include <boost/preprocessor/stringize.hpp>

/***
 *** Name:        W_WRAP
 *** Proto:       W_WRAP(id,...)
 *** Arg:         id   The name of the macro being wrapped.
 *** Arg:         ...  The code of the macro.
 *** Description: Use W_WRAP to construct a macro having multiple statements.
 ***              Typically such macros are written inside a 'do...while (0)' block.
 ***              W_WRAP does that and adds the name of the macro to the code (id) in
 ***              order to help the debugging phase.
 ***/
#define W_WRAP(id,...)                                         \
    do { __VA_ARGS__ } while (0 && BOOST_PP_STRINGIZE(id))

#endif
