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


#ifndef WDEBUG_EXPAND
# include <wondermacros/array/dynamic_stack.h>
# include <wondermacros/meta/declare.h>
#endif


#ifndef WCONF_STACK
# define WCONF_STACK
#endif


#undef WCONF_STACK_DECLARE_AND_INIT
#define WCONF_STACK_DECLARE_AND_INIT W_DECLARE(0, void** stack = NULL)


#undef WCONF_STACK_FREE
#define WCONF_STACK_FREE W_DYNAMIC_STACK_FREE(stack)


#undef WCONF_STACK_PUSH_PTR
#define WCONF_STACK_PUSH_PTR(p) W_DYNAMIC_STACK_PUSH(stack, p)


#undef WCONF_STACK_POP_PTR
#define WCONF_STACK_POP_PTR() W_DYNAMIC_STACK_POP(stack)


#undef WCONF_STACK_PEEK_PTR
#define WCONF_STACK_PEEK_PTR() W_DYNAMIC_STACK_PEEK(stack)


#undef WCONF_STACK_SWAP_PTRS
#define WCONF_STACK_SWAP_PTRS(x, y) W_DYNAMIC_ARRAY_SWAP(void*, stack, x, y)
