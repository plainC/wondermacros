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
#include <boost/preprocessor/control/if.hpp>
#ifndef WDEBUG_EXPAND
# include <wondermacros/array/dynamic_stack.h>
#endif


#ifndef W_TREE_NEXT
# define W_TREE_NEXT(tree,ix) ((tree)->next[ix])
#endif

#ifndef W_TREE_GET_DEGREE
# include <wondermacros/array/get_size.h>
# define W_TREE_GET_DEGREE(tree) ((int) W_ARRAY_GET_SIZE((tree)->next))
#endif

#ifndef W_REVERSED
# define W_REVERSED 0
#endif


#define W_TREE_NEXT_LEFTMOST(tree)                                             \
    W_TREE_NEXT(tree,0)

#define W_TREE_NEXT_RIGHTMOST(tree)                                            \
    W_TREE_NEXT(tree,W_TREE_GET_DEGREE(tree)-1)

#define W_TREE_FOR_EACH_IMMEDIATE(T,node,tree)                                 \
    W_DECLARE(W_CAT(node,10), T* node)                                         \
    for (int W_CAT(node,_ix)=0; W_CAT(node,_ix) < W_TREE_GET_DEGREE(node)      \
         && (node = W_TREE_NEXT(tree,W_CAT(node,_ix)),1); W_CAT(node,_ix)++)   \
        if (node == NULL)                                                      \
            ;                                                                  \
        else

#define W_TREE_FOR_EACH_IMMEDIATE_REVERSED(T,node,tree)                        \
    W_DECLARE(W_CAT(node,10), T* node)                                         \
    for (int W_CAT(node,_ix) = W_TREE_GET_DEGREE(node)-1;                      \
         W_CAT(node,_ix) >= 0                                                  \
         && (node = W_TREE_NEXT(tree, W_CAT(node,_ix)),1);                     \
      W_CAT(node,_ix)--)                                                       \
        if (node == NULL)                                                      \
            ;                                                                  \
        else

/***
 *** Name:        W_TREE_FOR_EACH_PREORDER
 *** Proto:       W_TREE_FOR_EACH_PREORDER(T,node,self)
 *** Arg:         T          type name of tree nodes
 *** Arg:         node       name of the free variable
 *** Arg:         self       a tree
 *** Description: Use W_TREE_FOR_EACH_PREORDER to traverse a tree structure iteratively in preorder.
 *** Notes:       Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
 ***/
#define W_TREE_FOR_EACH_PREORDER(T,node,self)                                  \
    W_DECLARE(W_CAT(node,1), T** W_ID(stack) = NULL)                           \
    W_DECLARE(W_CAT(node,2), T* node)                                          \
    W_DECLARE(W_CAT(node,3), T* W_ID(root) = (self))                           \
    W_BEFORE(W_CAT(node,4),                                                    \
        W_DYNAMIC_STACK_PUSH(W_ID(stack), W_ID(root) );                        \
    )                                                                          \
    if (W_ID(root) == NULL)                                                    \
        ;                                                                      \
    else                                                                       \
        while (!W_DYNAMIC_STACK_IS_EMPTY(W_ID(stack)))                         \
            W_BEFORE(W_CAT(node,5), (node) = W_DYNAMIC_STACK_POP(W_ID(stack))) \
            W_AFTER(W_CAT(node,6),                                             \
                if (node) {                                                    \
                    BOOST_PP_IF(W_REVERSED,                                    \
                        W_TREE_FOR_EACH_IMMEDIATE,                             \
                        W_TREE_FOR_EACH_IMMEDIATE_REVERSED)                    \
                    (T,W_ID(tmp), node)                                        \
                        W_DYNAMIC_STACK_PUSH(W_ID(stack), W_ID(tmp));          \
                }                                                              \
            )                                                                  \
    /**/


/***
 *** Name:        W_TREE_FOR_EACH_POSTORDER
 *** Proto:       W_TREE_FOR_EACH_POSTORDER(T,node,self)
 *** Arg:         T          type name of tree nodes
 *** Arg:         node       name of the free variable
 *** Arg:         self       a tree
 *** Description: Use W_TREE_FOR_EACH_POSTORDER to traverse a tree structure iteratively in postorder.
 *** Notes:       Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
 ***/
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

#define W_TREE_FREE(T,root) \
    W_TREE_FOR_EACH_POSTORDER(T,W_ID(_TREE_FREE_),root) \
        W_FREE(W_ID(_TREE_FREE_))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#else
# include <wondermacros/misc/struct_init.h>
# include <wondermacros/misc/struct_new.h>
#endif

W_TEST(W_TREE_FOR_EACH_PREORDER,
    struct bintree {
        int value;
        struct bintree* next[2];
    };
    struct bintree* root = W_STRUCT_NEW(struct bintree, .value=45,
        .next[0] = W_STRUCT_NEW(struct bintree, .value=13,
            .next[0] = W_STRUCT_NEW(struct bintree, .value=7),
            .next[1] = W_STRUCT_NEW(struct bintree, .value=19)),
        .next[1] = W_STRUCT_NEW(struct bintree, .value=74));

    int correct[] = {45,13,7,19,74};
    int ix=0;

#undef W_REVERSED
#define W_REVERSED 0
    W_TREE_FOR_EACH_PREORDER(struct bintree, node, root)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;

    W_TREE_FREE(struct bintree, root);
)

W_TEST(W_TREE_FOR_EACH_PREORDER_reversed,
    struct bintree {
        int value;
        struct bintree* next[2];
    };

    struct bintree* root = W_STRUCT_NEW(struct bintree, .value=45,
        .next[0] = W_STRUCT_NEW(struct bintree, .value=13,
            .next[0] = W_STRUCT_NEW(struct bintree, .value=7),
            .next[1] = W_STRUCT_NEW(struct bintree, .value=19)),
        .next[1] = W_STRUCT_NEW(struct bintree, .value=74));

    int correct[] = {45,74,13,19,7};
    int ix=0;

#undef W_REVERSED
#define W_REVERSED 1
    W_TREE_FOR_EACH_PREORDER(struct bintree, n, root)
        W_TEST_ASSERT(n->value == correct[ix++], "Value mismatch");

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;

    W_TREE_FREE(struct bintree, root);
)


W_TEST(W_TREE_FOR_EACH_POSTORDER,
    struct bintree {
        int value;
        struct bintree* next[2];
    };
    struct bintree* root = W_STRUCT_NEW(struct bintree, .value=45,
        .next[0] = W_STRUCT_NEW(struct bintree, .value=13,
            .next[0] = W_STRUCT_NEW(struct bintree, .value=7),
            .next[1] = W_STRUCT_NEW(struct bintree, .value=19)),
        .next[1] = W_STRUCT_NEW(struct bintree, .value=74));

    int correct[] = {7,19,13,74,45};
    int ix=0;

#undef W_REVERSED
#define W_REVERSED 0
    W_TREE_FOR_EACH_POSTORDER(struct bintree, np, root) {
        W_TEST_ASSERT(np->value == correct[ix++], "Value mismatch");
        free(np);
    }

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;
)

W_TEST(W_TREE_FOR_EACH_POSTORDER_reversed,
    struct bintree {
        int value;
        struct bintree* next[2];
    };
    struct bintree* root = W_STRUCT_NEW(struct bintree, .value=45,
        .next[0] = W_STRUCT_NEW(struct bintree, .value=13,
            .next[0] = W_STRUCT_NEW(struct bintree, .value=7),
            .next[1] = W_STRUCT_NEW(struct bintree, .value=19)),
        .next[1] = W_STRUCT_NEW(struct bintree, .value=74));

    int correct[] = {74,19,7,13,45};
    int ix=0;

#undef W_REVERSED
#define W_REVERSED 1
    W_TREE_FOR_EACH_POSTORDER(struct bintree, np, root) {
        W_TEST_ASSERT(np->value == correct[ix++], "Value mismatch: %d (at %d)", correct[ix-1], ix-1);
        free(np);
    }

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;
)

#endif
