/* (C) Copyright 2019, 2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#include <stdint.h>

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
 *** Arg:         TreeRoot   a tree (root node)
 *** Description: Use W_TREE_FOR_EACH_PREORDER to traverse a tree structure iteratively in preorder.
 *** Notes:       Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
 ***              Also define what stack is to be used by defining PUSH_PTR(p), PEEK_PTR(), SWAP_PTRS(ix1,ix2) and POP_PTR() macros.
 ***              Stack needs to be available before calling this macro and it must
 ***              have space for the depth of the tree, or have the capability to grow.
 ***/
#define W_TREE_FOR_EACH_PREORDER(T,node,TreeRoot)                        \
   W_BEFORE(_1,                                                          \
        PUSH_PTR( TreeRoot );                                            \
        if( PEEK_PTR() ) {                                               \
            PUSH_PTR( NULL );                                            \
            SWAP_PTRS( 0, 1 );                                           \
        }                                                                \
    )                                                                    \
    for( T* node = POP_PTR(); node; node = POP_PTR() )                   \
        W_BEFORE(_2,                                                     \
            BOOST_PP_IF(                                                 \
                W_REVERSED,                                              \
                for( int W_ID(i) = 0, W_ID(d) = W_TREE_GET_DEGREE(node); \
                        W_ID(i) < W_ID(d);                               \
                        W_ID(i)++ ),                                     \
                for( int W_ID(i) = W_TREE_GET_DEGREE(node) - 1;          \
                        W_ID(i) >= 0;                                    \
                        W_ID(i)-- )                                      \
            )                                                            \
                if( W_TREE_NEXT(node, W_ID(i) ) )                        \
                    PUSH_PTR( W_TREE_NEXT(node, W_ID(i) ) );             \
        )                                                                \
    /**/

#define W_UP 0
#define W_DOWN 1

/***
 *** Name:        W_TREE_FOR_EACH_POSTORDER
 *** Proto:       W_TREE_FOR_EACH_POSTORDER(T,node,TreeRoot)
 *** Arg:         T          type name of tree nodes
 *** Arg:         node       name of the free variable
 *** Arg:         TreeRoot   a tree
 *** Description: Use W_TREE_FOR_EACH_POSTORDER to traverse a tree structure iteratively in postorder.
 *** Notes:       Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
 ***              Also define what stack is to be used by defining PUSH_TAGGED_PTR(p), PEEK_TAGGED_PTR(), SWAP_PTRS(ix1,ix2) and POP_TAGGED_PTR() macros.
 ***              Stack needs to be available before calling this macro and it must
 ***              have space for the depth of the tree, or have the capability to grow.
 ***/
#define W_TREE_FOR_EACH_POSTORDER(Type, node, TreeRoot)                     \
    W_DECLARE(_0, int W_ID(t))                                              \
    W_BEFORE(_1,                                                            \
        PUSH_TAGGED_PTR( TreeRoot, W_DOWN );                                \
        if( PEEK_TAGGED_PTR( W_ID(t) ) ) {                                  \
            PUSH_TAGGED_PTR( NULL, W_DOWN );                                \
            SWAP_PTRS( 0, 1 );                                              \
        }                                                                   \
    )                                                                       \
    for( Type* W_ID(l), *node = POP_TAGGED_PTR(W_ID(t));                    \
            node; node = POP_TAGGED_PTR(W_ID(t)) )                          \
        W_BEFORE(_2,                                                        \
            if( W_ID(t) == W_DOWN ) {                                       \
                do {                                                        \
                    W_ID(l) = NULL;                                         \
                    PUSH_TAGGED_PTR( node, W_UP );                          \
                    BOOST_PP_IF(                                            \
                        W_REVERSED,                                         \
                        for( int W_ID(i) = 0;                               \
                                W_ID(i) < W_TREE_GET_DEGREE(node);          \
                                W_ID(i)++ )                                 \
                        ,                                                   \
                        for( int W_ID(i) = W_TREE_GET_DEGREE(node) - 1;     \
                                W_ID(i) >= 0;                               \
                                W_ID(i)-- )                                 \
                    )                                                       \
                        if( W_TREE_NEXT(node, W_ID(i) ) ) {                 \
                            W_ID(l) = W_TREE_NEXT(node, W_ID(i));           \
                            PUSH_TAGGED_PTR( W_ID(l), W_DOWN );             \
                        }                                                   \
                     node = W_ID(l) ?                                       \
                             POP_TAGGED_PTR(W_ID(t)) : node;                \
                } while( W_ID(l) );                                         \
                node = POP_TAGGED_PTR(W_ID(t));                             \
            }                                                               \
        )                                                                   \
    /**/


/***
 *** Name:        W_TREE_FREE
 *** Proto:       W_TREE_FREE(T,self)
 *** Arg:         T          type name of tree nodes
 *** Arg:         self       a tree
 *** Description: Use W_TREE_FREE to free all nodes in a tree.
 *** Notes:       Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
 ***              Also define what stack is to be used by defining PUSH_TAGGED_PTR(p), PEEK_TAGGED_PTR(), SWAP_PTRS(ix1,ix2) and POP_TAGGED_PTR() macros.
 ***              Stack needs to be available before calling this macro and it must
 ***              have space for the depth of the tree, or have the capability to grow.
 ***/
#define W_TREE_FREE(T,root)                                              \
    W_TREE_FOR_EACH_POSTORDER(T,W_ID(_TREE_FREE_),root)                  \
        W_FREE(W_ID(_TREE_FREE_))

/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#else
# include <wondermacros/misc/struct_init.h>
# include <wondermacros/misc/struct_new.h>
# include <wondermacros/array/dynamic_stack.h>
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

    void** stack = NULL;

#undef W_REVERSED
#define W_REVERSED 0

#define PUSH_PTR(p) W_DYNAMIC_STACK_PUSH(stack, p)
#define POP_PTR() W_DYNAMIC_STACK_POP(stack)
#define PEEK_PTR() W_DYNAMIC_STACK_PEEK(stack)
#define SWAP_PTRS(x, y) W_DYNAMIC_ARRAY_SWAP(void*, stack, x, y)

    W_TREE_FOR_EACH_PREORDER(struct bintree, node, root)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");

    W_DYNAMIC_STACK_FREE(stack);

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;

#define PUSH_TAGGED_PTR(p,t) W_DYNAMIC_STACK_PUSH(stack, (void*) ((uintptr_t)(p) | ((uintptr_t)(((t)&1)))))
#define POP_TAGGED_PTR(t) (t=(uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&1, (void*)((uintptr_t)W_DYNAMIC_STACK_POP(stack)&(~1ull)))
#define PEEK_TAGGED_PTR(t) (t=(uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&1, (void*)((uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&(~1ull)))

    W_TREE_FREE(struct bintree, root);
    W_DYNAMIC_STACK_FREE(stack);
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

    void** stack = NULL;

#undef W_REVERSED
#define W_REVERSED 1
    W_TREE_FOR_EACH_PREORDER(struct bintree, n, root)
        W_TEST_ASSERT(n->value == correct[ix++], "Value mismatch");

    W_DYNAMIC_STACK_FREE(stack);

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;

    W_TREE_FREE(struct bintree, root);
    W_DYNAMIC_STACK_FREE(stack);
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

    void** stack = NULL;

    W_TREE_FOR_EACH_POSTORDER(struct bintree, np, root) {
        W_TEST_ASSERT(np->value == correct[ix++], "Value mismatch: %d", np->value);
        free(np);
    }

    W_DYNAMIC_STACK_FREE(stack);

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

    void** stack = NULL;

    W_TREE_FOR_EACH_POSTORDER(struct bintree, np, root) {
        W_TEST_ASSERT(np->value == correct[ix++], "Value mismatch: %d (at %d)", correct[ix-1], ix-1);
        free(np);
    }

    W_DYNAMIC_STACK_FREE(stack);

    W_TEST_ASSERT(ix == 5, "for_each did not traverse tree");
    ix=0;
)

#endif
