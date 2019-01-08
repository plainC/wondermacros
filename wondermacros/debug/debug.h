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

#ifndef __W_DEBUG_H
#define __W_DEBUG_H

#include <boost/preprocessor/control/expr_if.hpp>

#ifndef W_DEBUG_FUNC
# include <stdio.h>
# define W_DEBUG_FUNC fprintf
#endif

#ifndef W_DEBUG_FILE
# define W_DEBUG_FILE stderr
#endif

#ifndef W_DEBUG_APPEND_NL
# define W_DEBUG_APPEND_NL 1
#endif


#ifdef NDEBUG

# define W_DEBUG(...)

#else

/***
 *** Name:        W_DEBUG
 *** Proto:       W_DEBUG(fmt,...)
 *** Arg:         fmt          a format (like printf)
 *** Arg:         ...          optional arguments
 *** Description: Use W_DEBUG to write a debug message.
 *** Notes:       Redefine W_DEBUG_FUNC, W_DEBUG_FILE and W_DEBUG_APPEND_NL change the default behaviour.
 ***/
# define W_DEBUG(...)                                                         \
    do {                                                                      \
        W_DEBUG_FUNC(W_DEBUG_FILE, "[%s:%d] ", __FILE__, __LINE__);           \
        W_DEBUG_FUNC(W_DEBUG_FILE, __VA_ARGS__);                              \
        BOOST_PP_EXPR_IF(W_DEBUG_APPEND_NL,W_DEBUG_FUNC(W_DEBUG_FILE, "\n");) \
    } while (0)

# endif

#endif
