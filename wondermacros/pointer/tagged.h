/* (C) Copyright 2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_TAGGED_H
#define __W_TAGGED_H

#include <stdint.h>


#ifndef W_TAG_LENGTH
#define W_TAG_LENGTH 3
#endif


#define W_TAG_MASK ((0x1ull << (W_TAG_LENGTH)) - 1)


/***
 *** Name:        W_TAGGED_PTR_SET
 *** Proto:       W_TAGGED_PTR_SET(p, tag)
 ***
 *** Arg:         p     a pointer
 *** Arg:         tag   a tag (length in bits is set by W_TAG_LENGTH)
 ***
 *** Description: Use W_TAGGED_PTR_SET to set a pointer with a tag.
 *** Notes:       Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
 ***/
#define W_TAGGED_PTR_SET(p, tag)                                  \
    ((void*)((uintptr_t)(p)|((uintptr_t)(((tag)&W_TAG_MASK)))))   \
    /**/


/***
 *** Name:        W_TAGGED_PTR_GET_PTR
 *** Proto:       W_TAGGED_PTR_GET_PTR(p)
 ***
 *** Arg:         p     a pointer
 ***
 *** Description: Use W_TAGGED_PTR_GET_PTR to get the pointer without tag.
 *** Notes:       Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
 ***/
#define W_TAGGED_PTR_GET_PTR(p)                                   \
    ((void*)((uintptr_t)(p) & (~W_TAG_MASK)))                     \
    /**/


/***
 *** Name:        W_TAGGED_PTR_GET_TAG
 *** Proto:       W_TAGGED_PTR_GET_TAG(p)
 ***
 *** Arg:         p     a pointer
 ***
 *** Description: Use W_TAGGED_PTR_GET_TAG to get the tag of tagged pointer.
 *** Notes:       Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
 ***/
#define W_TAGGED_PTR_GET_TAG(p)                                   \
    ((uintptr_t)(p) & W_TAG_MASK)                                 \
    /**/


#endif
