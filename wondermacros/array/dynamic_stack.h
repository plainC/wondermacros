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

#ifndef __W_DYNAMIC_STACK_H
#define __W_DYNAMIC_STACK_H

#include <wondermacros/array/dynamic_array.h>


/***
 *** Name:        W_DYNAMIC_STACK_SIZE
 *** Proto:       W_DYNAMIC_STACK_SIZE(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_SIZE to get the number of elements in the stack.
 ***/
#define W_DYNAMIC_STACK_SIZE(stack) W_DYNAMIC_ARRAY_SIZE(stack)

/***
 *** Name:        W_DYNAMIC_STACK_PEEK
 *** Proto:       W_DYNAMIC_STACK_PEEK(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_PEEK to peek the toppest element in the stack.
 *** Note:        If the stack is empty, the behaviour is undefined.
 ***/
#define W_DYNAMIC_STACK_PEEK(stack) W_DYNAMIC_ARRAY_PEEK_LAST(stack)

/***
 *** Name:        W_DYNAMIC_STACK_PEEK_SAFE
 *** Proto:       W_DYNAMIC_STACK_PEEK_SAFE(stack,value)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 *** Arg:         value   A value to be returned if stack is empty
 ***
 *** Description: Use W_DYNAMIC_STACK_PEEK_SAFE to peek the toppest element in the stack.
 ***              If the stack is empty, the given value is returned.
 ***/
#define W_DYNAMIC_STACK_PEEK_SAFE(stack,value) W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(stack,value)

/***
 *** Name:        W_DYNAMIC_STACK_POP
 *** Proto:       W_DYNAMIC_STACK_POP(array)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_POP to get and remove the last element in the stack.
 *** Note:        If the stack is empty, the behavious is undefined.
 ***/
#define W_DYNAMIC_STACK_POP(stack) W_DYNAMIC_ARRAY_STEAL_LAST(stack)

/***
 *** Name:        W_DYNAMIC_STACK_ALLOC_SIZE
 *** Proto:       W_DYNAMIC_STACK_ALLOC_SIZE(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_ALLOC_SIZE to get the current allocation size.
 ***/
#define W_DYNAMIC_STACK_ALLOC_SIZE(stack) W_DYNAMIC_ARRAY_ALLOC_SIZE(stack)

/***
 *** Name:        W_DYNAMIC_STACK_IS_EMPTY
 *** Proto:       W_DYNAMIC_STACK_IS_EMPTY(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_IS_EMPTY to check if a dynamic stack is empty.
 ***/
#define W_DYNAMIC_STACK_IS_EMPTY(stack) (W_DYNAMIC_STACK_SIZE(stack) == 0)

/***
 *** Name:        W_DYNAMIC_STACK_ELEM_SIZE
 *** Proto:       W_DYNAMIC_STACK_ELEM_SIZE(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_ELEM_SIZE to get the element size.
 ***/
#define W_DYNAMIC_STACK_ELEM_SIZE(stack) W_DYNAMIC_STACK_ELEM_SIZE(stack)

/***
 *** Name:        W_DYNAMIC_STACK_INIT
 *** Proto:       W_DYNAMIC_STACK_INIT(stack,T,init_size)
 ***
 *** Arg:         stack     A pointer to a dynamic stack
 *** Arg:         T         Type name of stack elements
 *** Arg:         init_size Initial allocation size for the stack
 ***
 *** Description: Use W_DYNAMIC_STACK_INIT to initialize a dynamic stack.
 ***/
#define W_DYNAMIC_STACK_INIT(stack,T,init_size)                                  \
    W_DYNAMIC_ARRAY_INIT(stack,T,init_size)

/***
 *** Name:        W_DYNAMIC_STACK_CLEAR
 *** Proto:       W_DYNAMIC_STACK_CLEAR(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_CLEAR to clear a dynamic stack.
 ***/
#define W_DYNAMIC_STACK_CLEAR(stack) W_DYNAMIC_ARRAY_CLEAR(stack)

/***
 *** Name:        W_DYNAMIC_STACK_FREE
 *** Proto:       W_DYNAMIC_STACK_FREE(stack)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_FREE to free a dynamic stack.
 ***/
#define W_DYNAMIC_STACK_FREE(stack) W_DYNAMIC_ARRAY_FREE(stack)

/***
 *** Name:        W_DYNAMIC_STACK_PUSH
 *** Proto:       W_DYNAMIC_STACK_PUSH(stack,...)
 ***
 *** Arg:         stack   A pointer to a dynamic stack
 *** Arg:         ...     Values to be pushed into a dynamic stack
 ***
 *** Description: Use W_DYNAMIC_STACK_PUSH to push values to a dynamic stack.
 ***/
#define W_DYNAMIC_STACK_PUSH(stack,...) W_DYNAMIC_ARRAY_PUSH(stack,__VA_ARGS__)

#endif
