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
#ifndef __W_TREE_FOR_EACH_H
#define __W_TREE_FOR_EACH_H

#include <wondermacros/meta/after.h>
#include <wondermacros/meta/before.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/meta/cat.h>
#ifndef WDEBUG_EXPAND
# include <wondermacros/array/dynamic_stack.h>
#endif


#ifndef W_TREE_NEXT
# define W_TREE_NEXT(tree,ix) ((tree)->next[ix])
#endif

#ifndef W_TREE_GET_DEGREE
# include <wondermacros/array/array_get_size.h>
# define W_TREE_GET_DEGREE(tree) W_ARRAY_GET_SIZE((tree)->next)
#endif

#ifndef W_REVERSED
# define W_REVERSED 0
#endif


#define W_TREE_NEXT_LEFTMOST(tree)                                             \
    W_TREE_NEXT(tree,0)

#define W_TREE_NEXT_RIGHTMOST(tree)                                            \
    W_TREE_NEXT(tree,W_TREE_GET_DEGREE(tree)-1)

#define W_TREE_FOR_EACH_IMMEDIATE(T,node,tree)                                 \
    W_DECLARE(10, T* node)                                                     \
    for (int W_CAT(node,_ix)=0; W_CAT(node,_ix) < W_TREE_GET_DEGREE(node)      \
         && (node = W_TREE_NEXT(tree,W_CAT(node,_ix)),1); W_CAT(node,_ix)++)   \
        if (node == NULL)                                                      \
            ;                                                                  \
        else

#define W_TREE_FOR_EACH_IMMEDIATE_REVERSED(T,node,tree)                        \
    W_DECLARE(10, T* node)                                                     \
    for (int W_CAT(node,_ix) = W_TREE_GET_DEGREE(node)-1;                      \
         W_CAT(node,_ix) >= 0                                                  \
         && (node = W_TREE_NEXT(tree, W_CAT(node,_ix)),1);                     \
      W_CAT(node,_ix)--)                                                       \
        if (node == NULL)                                                      \
            ;                                                                  \
        else

#define W_TREE_FOR_EACH_PREORDER(T,node,self)                                  \
    W_DECLARE(1, T** W_ID(stack) = NULL)                                       \
    W_DECLARE(2, T* node)                                                      \
    W_DECLARE(22, T* W_ID(root) = (self))                                      \
    W_BEFORE(3,                                                                \
        W_DYNAMIC_STACK_PUSH(W_ID(stack), W_ID(root) );                        \
    )                                                                          \
    if (W_ID(root) == NULL)                                                    \
        ;                                                                      \
    else                                                                       \
        while (!W_DYNAMIC_STACK_IS_EMPTY(W_ID(stack)))                         \
            W_BEFORE(4, (node) = W_DYNAMIC_STACK_POP(W_ID(stack)))             \
            W_AFTER(5,                                                         \
                if (node)                                                      \
                    BOOST_PP_IF(W_REVERSED,                                    \
                        W_TREE_FOR_EACH_IMMEDIATE_REVERSED,                    \
                        W_TREE_FOR_EACH_IMMEDIATE)                             \
                    (T,W_ID(tmp), node)                                        \
                        W_DYNAMIC_STACK_PUSH(W_ID(stack), W_ID(tmp));          \
            )                                                                  \
    /**/


#define W_TREE_FOR_EACH_POSTORDER(T,Child,self)                                                \
    W_DECLARE(1, T *Child)                                                                     \
    W_DECLARE(11, T* W_ID(node) = (self))                                                      \
    W_DECLARE(2, T** W_ID(stack) = NULL )                                                      \
    if (W_ID(node) == NULL)                                                                    \
        ;                                                                                      \
    else                                                                                       \
        W_BEFORE(4, goto W_LABEL(6,Child); )                                                   \
        while (!W_DYNAMIC_STACK_IS_EMPTY(W_ID(stack)))                                         \
            W_BEFORE (5,                                                                       \
              W_LABEL(6,Child):                                                                \
                while (W_ID(node)) {                                                           \
                    BOOST_PP_IF(W_REVERSED,                                                    \
                        W_TREE_FOR_EACH_IMMEDIATE_REVERSED(T,W_CAT(Child,_child), W_ID(node))  \
                            if (W_CAT(Child,_child,_ix) < W_TREE_GET_DEGREE(W_ID(node))-1)     \
                                W_DYNAMIC_STACK_PUSH( W_ID(stack),W_CAT(Child,_child) );       \
                        W_DYNAMIC_STACK_PUSH( W_ID(stack),W_ID(node) );                        \
                        W_ID(node) = W_TREE_NEXT_RIGHTMOST(W_ID(node));                        \
                        , /* else */                                                           \
                        W_TREE_FOR_EACH_IMMEDIATE(T,W_CAT(Child,_child), W_ID(node))           \
                            if (W_CAT(Child,_child,_ix) > 0)                                   \
                                W_DYNAMIC_STACK_PUSH( W_ID(stack),W_CAT(Child,_child) );       \
                        W_DYNAMIC_STACK_PUSH( W_ID(stack),W_ID(node) );                        \
                        W_ID(node) = W_TREE_NEXT_LEFTMOST(W_ID(node));                         \
                    )                                                                          \
                }                                                                              \
                W_ID(node) = W_DYNAMIC_STACK_POP( W_ID(stack) );                               \
                BOOST_PP_IF(W_REVERSED,                                                        \
                    if (W_ID(node) && W_TREE_NEXT_LEFTMOST(W_ID(node))                         \
                        && W_DYNAMIC_STACK_PEEK_SAFE(W_ID(stack),NULL) == W_TREE_NEXT_LEFTMOST(W_ID(node)) ) { \
                        W_DYNAMIC_STACK_POP(W_ID(stack));                                      \
                        W_DYNAMIC_STACK_PUSH( W_ID(stack),W_ID(node) );                        \
                        W_ID(node) = W_TREE_NEXT_LEFTMOST(W_ID(node));                         \
                        goto W_LABEL(6,Child);                                                 \
                    }                                                                          \
                    , /* else */                                                               \
                    if (W_ID(node) && W_TREE_NEXT_RIGHTMOST(W_ID(node))                        \
                        && W_DYNAMIC_STACK_PEEK_SAFE(W_ID(stack),NULL) == W_TREE_NEXT_RIGHTMOST(W_ID(node)) ) { \
                        W_DYNAMIC_STACK_POP(W_ID(stack));                                      \
                        W_DYNAMIC_STACK_PUSH( W_ID(stack),W_ID(node) );                        \
                        W_ID(node) = W_TREE_NEXT_RIGHTMOST(W_ID(node));                        \
                        goto W_LABEL(6,Child);                                                 \
                    }                                                                          \
                )                                                                              \
                Child = W_ID(node);                                                            \
                W_ID(node) = NULL;                                                             \
            )                                                                                  \
            /**/

#endif

