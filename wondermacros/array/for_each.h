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

#ifndef __W_ARRAY_FOR_EACH_H
#define __W_ARRAY_FOR_EACH_H

#include <boost/preprocessor/facilities/overload.hpp>
#include <wondermacros/meta/id.h>
#include <wondermacros/array/get_size.h>
#include <wondermacros/configs/array_collection.h>
#include <wondermacros/meta/declare.h>

/***
 *** Name:        W_ARRAY_FOR_EACH
 *** Proto:       W_ARRAY_FOR_EACH(T,elem,array[,size])
 ***
 *** Arg:         T      a type name of array elements
 *** Arg:         elem   a free identifier name
 *** Arg:         array  a pointer to an array
 *** Arg:         size   number of elements in the array (if omitted static size obtained using sizeof is used)
 ***
 *** Description: Use W_ARRAY_FOR_EACH to iterate all elements of an array.
 *** Note:        The index of the element is stored in 'elem ## _ix'.
 *** Example:     int array[] = { 7, 3, 6, 2, 9 };
 ***              W_ARRAY_FOR_EACH(int, a, array) {
 ***                  printf("%d: %d\n", a_ix, a);
 ***              }
 ***/
#define W_ARRAY_FOR_EACH(T,elem,...)                                        \
    BOOST_PP_OVERLOAD(_W_ARRAY_FOR_EACH_,__VA_ARGS__)(T,elem,__VA_ARGS__)

#define _W_ARRAY_FOR_EACH_1(T,elem,array)                                   \
    _W_ARRAY_FOR_EACH(T,elem,array,W_ARRAY_GET_SIZE(array))

#define _W_ARRAY_FOR_EACH_2(T,elem,array,size)                              \
    _W_ARRAY_FOR_EACH(T,elem,array,size)

#define _W_ARRAY_FOR_EACH(T,elem,array,Size)                                \
    W_DECLARE(_array_for_each_, T elem)                                     \
    for (int elem ## _ix=0, W_ID(size) = (Size);                            \
         elem ## _ix < W_ID(size) && (elem = W_GET(array, elem ## _ix), 1); \
         ++elem ## _ix)


#define W_ARRAY_FOR_EACH_PTR(T,elemp,array,Size)                             \
    W_DECLARE(_array_for_each_, T* elemp)                                    \
    for (int elemp ## _ix=0, W_ID(size) = (Size);                             \
         elemp ## _ix < W_ID(size) && (elemp = &W_GET(array, elemp ## _ix), 1); \
         ++elemp ## _ix)

#endif
