/* (C) is Copyright 2015,2018 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_MAX_H
#define __W_MAX_H

#include <boost/preprocessor/facilities/overload.hpp>

#ifndef W_COMPARE
# include "wondermacros/configs/compare.h"
#endif

#ifndef W_GE
# define W_GE(a,b) ((a) >= (b))
#endif

#ifndef W_ZERO
# define W_ZERO 0
#endif


/***
 *** Name:        W_MAX
 *** Proto:       W_MAX(...)
 *** Arg:         ...          values to be compared (from one up to four)
 *** Description: Use W_MAX to get the maximum of given values.
 ***/
#define W_MAX(...) BOOST_PP_OVERLOAD(_W_MAX_,__VA_ARGS__)(__VA_ARGS__)

#define _W_MAX_1(a) (a)
#define _W_MAX_2(a,b) (W_GE(W_COMPARE(a,b), W_ZERO) ? (a) : (b))
#define _W_MAX_3(a,b,c) (W_GE(W_COMPARE(a,b), W_ZERO) ? _W_MAX_2(a,c) : _W_MAX_2(b,c))
#define _W_MAX_4(a,b,c,d) (W_GE(W_COMPARE(_W_MAX_2(a,b),_W_MAX_2(c,d)), W_ZERO) \
    ? _W_MAX_2(a,b) : _W_MAX_2(c,d))

#endif

