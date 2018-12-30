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

#ifndef __W_ARRAY_MOVE_RIGHT_H
#define __W_ARRAY_MOVE_RIGHT_H

#include <wondermacros/meta/id.h>

#define W_ARRAY_MOVE_RIGHT(array,size,pos,offset)                                  \
    do {                                                                           \
        int W_ID(elems) = (size);                                                  \
        int W_ID(step) = (offset);                                                 \
        int W_ID(Pos) = (pos);                                                     \
        for (int W_ID(i)=W_ID(elems)-1+W_ID(step); W_ID(i) >= W_ID(Pos)+W_ID(step); W_ID(i)--) \
            (array)[W_ID(i)] = (array)[W_ID(i) - W_ID(step)];                      \
    } while (0)

#endif
