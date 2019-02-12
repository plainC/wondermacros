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

#ifndef __W_STRUCT_NEW_H
#define __W_STRUCT_NEW_H


#ifndef W_MALLOC
# define W_MALLOC malloc
#endif


/***
 *** Name:        W_STRUCT_NEW
 *** Proto:       W_STRUCT_NEW(T,ptr,...)
 *** Arg:         T     a type name
 *** Arg:         ...   initial values for the structure (e.g. '.x=1, .y=2' or just '1,2')
 *** Description: Use W_STRUCT_NEW to allocate and initialize a structure.
 ***/
#define W_STRUCT_NEW(T,...)      \
    W_STRUCT_INIT(T,W_MALLOC(sizeof(T)),__VA_ARGS__)


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_STRUCT_NEW,
    struct point {
       int x;
       int y;
       int z;
    };
    struct point* p = W_STRUCT_NEW(struct point, .x=1, .y=2, .z=3);
    W_TEST_ASSERT(p->x == 1, "Value mismatch");
    W_TEST_ASSERT(p->y == 2, "Value mismatch");
    W_TEST_ASSERT(p->z == 3, "Value mismatch");
    free(p);
)

#endif
