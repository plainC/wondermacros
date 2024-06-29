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
# include <alloca.h>
# include <wondermacros/meta/declare.h>
# include <wondermacros/meta/id.h>
# include <wondermacros/pointer/ref_void_ptr.h>
#endif


#ifndef WCONF_STACK
# define WCONF_STACK
#endif


#undef WCONF_STACK_DECLARE_AND_INIT
#define WCONF_STACK_DECLARE_AND_INIT                               \
    W_DECLARE(0a, void** W_ID(stack)=NULL)                         \
    W_DECLARE(0b, int W_ID(sp) = 0)                                \
    /**/


#undef WCONF_STACK_FREE
#define WCONF_STACK_FREE


#define W_ALLOCA_HEADER_TYPE                                       \
    struct {                                                       \
        int alloc_size;                                            \
    }                                                              \
    /**/


#define W_ALLOCA_GET_SIZE(stack)                                   \
    ((stack) ?                                                     \
        W_HIDDEN_OF(stack, W_ALLOCA_HEADER_TYPE, alloc_size) :     \
        0)                                                         \
    /**/


#define W_ALLOCA_RESIZE(stack, old_size, new_size)                  \
    do {                                                            \
        if ( (stack) == NULL ) {                                    \
            (stack) = alloca(1 * sizeof(stack[0]) +                 \
                             sizeof(W_ALLOCA_HEADER_TYPE));         \
            ((W_ALLOCA_HEADER_TYPE*)(stack))->alloc_size = 1;       \
            (stack) = W_REF_VOID_PTR((stack),                       \
                                     sizeof(W_ALLOCA_HEADER_TYPE)); \
            break;                                                  \
        }                                                           \
        if ( W_ALLOCA_GET_SIZE(stack) >= (new_size) )               \
            break;                                                  \
        void* W_ID(p) = alloca((new_size) * sizeof(stack[0]) +      \
                               sizeof(W_ALLOCA_HEADER_TYPE));       \
        ((W_ALLOCA_HEADER_TYPE*)W_ID(p))->alloc_size = (new_size);  \
        W_ID(p) = W_REF_VOID_PTR(W_ID(p),                           \
                                 sizeof(W_ALLOCA_HEADER_TYPE));     \
        memcpy(W_ID(p), (stack), (old_size) * sizeof(stack[0]));    \
        (stack) = W_ID(p);                                          \
    } while (0)                                                     \
    /**/


#undef WCONF_STACK_PUSH_PTR
#define WCONF_STACK_PUSH_PTR(p)                                    \
    do {                                                           \
        if (W_ID(sp) == W_ALLOCA_GET_SIZE(W_ID(stack)))            \
            W_ALLOCA_RESIZE(W_ID(stack),                           \
                            W_ID(sp),                              \
                            W_ALLOCA_GET_SIZE(W_ID(stack)) << 1);  \
        W_ID(stack)[W_ID(sp)++] = (p);                             \
    } while (0)                                                    \
    /**/


#undef WCONF_STACK_POP_PTR
#define WCONF_STACK_POP_PTR()                                      \
    ( W_ID(stack)[--W_ID(sp)] )                                    \
    /**/

#undef WCONF_STACK_PEEK_PTR
#define WCONF_STACK_PEEK_PTR()                                     \
    ( W_ID(stack)[W_ID(sp)-1] )                                    \
    /**/

#undef WCONF_STACK_SWAP_PTRS
#define WCONF_STACK_SWAP_PTRS(x, y)                                \
    do {                                                           \
        void* W_ID(swapt) = W_ID(stack)[W_ID(sp)-(x)-1];           \
        W_ID(stack)[W_ID(sp)-(x)-1] = W_ID(stack)[W_ID(sp)-(y)-1]; \
        W_ID(stack)[W_ID(sp)-(y)-1] = W_ID(swapt);                 \
    } while (0)                                                    \
    /**/
