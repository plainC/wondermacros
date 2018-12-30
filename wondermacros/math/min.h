/* (C) is Copyright 2015 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_MIN_H
#define __W_MIN_H

#include <boost/preprocessor/facilities/overload.hpp>

#ifndef W_COMPARE
# include "wondermacros/configs/compare.h"
#endif

/***
 *** Name:        W_MIN
 *** Proto:       W_MIN(...)
 *** Arg:         ...          values to be compared (from one up to four)
 *** Description: Use W_MIN to get the minimum of given values.
 ***/
#define W_MIN(...) BOOST_PP_OVERLOAD(_W_MIN_,__VA_ARGS__)(__VA_ARGS__)

#define _W_MIN_1(a) (a)
#define _W_MIN_2(a,b) (W_COMPARE(a,b) <= 0 ? (a) : (b))
#define _W_MIN_3(a,b,c) (W_COMPARE(a,b) <= 0 ? _W_MIN_2(a,c) : _W_MIN_2(b,c))
#define _W_MIN_4(a,b,c,d) (W_COMPARE(_W_MIN_2(a,b),_W_MIN_2(c,d)) <= 0 ? _W_MIN_2(a,b) : _W_MIN_2(c,d))

#endif

