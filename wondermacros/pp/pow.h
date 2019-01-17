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

#ifndef __W_PP_POW_H
#define __W_PP_POW_H

#define W_PP_POW(a,b) BOOST_PP_IF(b,BOOST_PP_IF(BOOST_PP_EQUAL(b,1),a,W_CAT(_W_PP_POW_,a,_,b)),0)

#define _W_PP_POW_2_2 4
#define _W_PP_POW_2_3 8
#define _W_PP_POW_2_4 16
#define _W_PP_POW_2_5 32
#define _W_PP_POW_2_6 64
#define _W_PP_POW_2_7 128

#define _W_PP_POW_3_2 9
#define _W_PP_POW_3_3 27
#define _W_PP_POW_3_4 81
#define _W_PP_POW_3_5 243

#define _W_PP_POW_5_2 25
#define _W_PP_POW_5_3 125

#define _W_PP_POW_7_2 49

#define _W_PP_POW_11_2 121
#define _W_PP_POW_13_2 169

#endif

