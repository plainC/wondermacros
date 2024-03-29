/* (C) Copyright 2015 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_ID_H
#define __W_ID_H

#include <boost/preprocessor/cat.hpp>

/***
 *** Name:        W_ID
 *** Proto:       W_ID(id)
 *** Arg:         id   identifier name
 *** Description: Use W_ID to provide a more hygienic identifier name to be used in a macro.
 *** Returns:     Expands to an identifier name.
 *** Notes:       Uses the line number and a prefix to avoid name conflicts. Since a macro
 ***              always expands to a single row all expansions will get the same line number.
 ***/
#define W_ID(id)                          \
    BOOST_PP_CAT(W_ID_ ## id, __LINE__)

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_ID,
    int W_ID(i) = 42;    W_TEST_ASSERT(W_ID(i) == 42, "Value mismatch");
)

#endif

