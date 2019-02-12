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

#ifndef __W_HIDDEN_OF_H
#define __W_HIDDEN_OF_H

#include <wondermacros/pointer/ref_void_ptr.h>

/***
 *** Name:        W_HIDDEN_CONTAINER_OF
 *** Proto:       W_HIDDEN_CONTAINER_OF(ptr,T)
 *** Arg:         ptr   a pointer to a structure having a hidden header.
 *** Arg:         T     type of the hidden header.
 *** Description: Use W_HIDDEN_CONTAINER_OF to get a pointer to the actual container of on object having a hidden header.
 ***/
#define W_HIDDEN_CONTAINER_OF(ptr,T) ((T*) W_REF_VOID_PTR(ptr, -sizeof(T)))

/***
 *** Name:        W_HIDDEN_OF
 *** Proto:       W_HIDDEN_OF(ptr,T,member)
 *** Arg:         ptr     a pointer to a structure having a hidden header.
 *** Arg:         T       type of the hidden header.
 *** Arg:         member  member field name of the header.
 *** Description: Use W_HIDDEN_OF to get a value of a field in the hidden header of a structure.
 ***/
#define W_HIDDEN_OF(ptr,T,member) (W_HIDDEN_CONTAINER_OF(ptr,T)->member)

#endif
