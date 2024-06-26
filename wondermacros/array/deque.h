/* (C) is Copyright 2018,2019,2024 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_DEQUE_H
#define __W_DEQUE_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/facilities/overload.hpp>

#include <wondermacros/math/log2.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/pointer/hidden_of.h>
#include <wondermacros/functions/round_up_pow2.h>


#ifndef W_MALLOC
# ifndef WDEBUG_EXPAND
#  include <stdlib.h>
# endif
# define W_MALLOC(size) malloc(size)
#endif

#ifndef W_MALLOC0
# ifndef WDEBUG_EXPAND
#  include <string.h>
# endif
# define W_MALLOC0(size) memset(malloc(size), 0, size)
#endif

#ifndef W_REALLOC
# define W_REALLOC realloc
#endif

#ifndef W_FREE
# define W_FREE free
#endif

#ifndef W_RAISE
# define W_RAISE(str)                                                      \
    do {                                                                   \
        fprintf(stderr, "%s\n", (str));                                    \
        exit(1);                                                           \
    } while (0)
#endif


#ifndef WDEBUG_EXPAND
#define W_DEQUE_HEADER_TYPE                                                \
    struct {                                                               \
        unsigned alloc_size_lg2;                                           \
        unsigned start;                                                    \
        unsigned end;                                                      \
    }
#endif


#define W_DEQUE_ALLOC_SIZE_LG2(deque)                                      \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, alloc_size_lg2)
#define W_DEQUE_ALLOC_SIZE(deque)                                          \
    (0x1U << W_DEQUE_ALLOC_SIZE_LG2(deque))
#define W_DEQUE_START(deque)                                               \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, start)
#define W_DEQUE_END(deque)                                                 \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, end)


#define W_DEQUE_IS_ALLOC_FULL(Q)                                           \
    (W_DEQUE_END(Q) == (W_DEQUE_START(Q) ^ W_DEQUE_ALLOC_SIZE(Q)))         \
    /**/


/***
 *** Name:        W_DEQUE_INIT
 *** Proto:       W_DEQUE_INIT(Q,alloc_size)
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         alloc_size  initial allocation size
 *** Description: Use W_DEQUE_INIT to initialize a deque. The given size is rounded up to next power of two.
 ***/
#define W_DEQUE_INIT(Q,alloc_size)                                         \
    do {                                                                   \
        unsigned W_ID(size) = W_LOG2(w_round_up_pow2_uint32(alloc_size));  \
        (Q) = W_MALLOC( W_DEQUE_ALLOC_SIZE_BYTES(Q, W_ID(size)) );         \
        if ((Q) == NULL) {                                                 \
            W_RAISE( "allocation error" );                                 \
        }                                                                  \
        (Q) = W_REF_VOID_PTR(Q, sizeof(W_DEQUE_HEADER_TYPE));              \
        W_DEQUE_ALLOC_SIZE_LG2(Q) = W_ID(size);                            \
        W_DEQUE_CLEAR(Q);                                                  \
    } while( 0 )                                                           \
    /**/

/***
 *** Name:        W_DEQUE_RESIZE
 *** Proto:       W_DEQUE_RESIZE(T,Q,new_size)
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         new_size    new allocation size
 *** Description: Use W_DEQUE_RESIZE to resize a deque. The given size is rounded up to next power of two.
 ***/
#define W_DEQUE_RESIZE(T,Q,new_size)                                       \
    do {                                                                   \
        T* W_ID(nq);                                                       \
        W_DEQUE_INIT( W_ID(nq), (new_size) );                              \
        W_DEQUE_FOR_EACH( T, e, Q )                                        \
            W_DEQUE_PUSH( W_ID(nq), e );                                   \
        W_DEQUE_FREE( Q );                                                 \
        (Q) = W_ID(nq);                                                    \
    } while( 0 )                                                           \
    /**/

/***
 *** Name:        W_DEQUE_FREE
 *** Proto:       W_DEQUE_FREE(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_FREE to free a deque.
 ***/
#define W_DEQUE_FREE(Q)                                                    \
    W_FREE(W_HIDDEN_CONTAINER_OF(Q, W_DEQUE_HEADER_TYPE))

#define W_DEQUE_ELEM_SIZE(Q)                                               \
    (sizeof((Q)[0]))


/***
 *** Name:        W_DEQUE_SIZE
 *** Proto:       W_DEQUE_SIZE(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_SIZE to get the number of elements in a deque.
 ***/
#define W_DEQUE_SIZE(Q) (                                                  \
    W_DEQUE_IS_ALLOC_FULL(Q) ? (                                           \
        W_DEQUE_ALLOC_SIZE(Q)                                              \
    ) : (                                                                  \
        (W_DEQUE_START(Q) <= W_DEQUE_ALLOC_SIZE(Q)) ? (                    \
            (W_DEQUE_END(Q) <= W_DEQUE_ALLOC_SIZE(Q)) ? (                  \
                (W_DEQUE_END(Q) - W_DEQUE_START(Q))                        \
            ) : (                                                          \
                (W_DEQUE_END(Q) - W_DEQUE_START(Q)) &                      \
                    (W_DEQUE_ALLOC_SIZE(Q)-1)                              \
            )                                                              \
        ) : (                                                              \
            W_DEQUE_END(Q) <= W_DEQUE_ALLOC_SIZE(Q) ? (                    \
                (W_DEQUE_END(Q) - W_DEQUE_START(Q)) &                      \
                    (W_DEQUE_ALLOC_SIZE(Q)-1)                              \
            ) : (                                                          \
                W_DEQUE_END(Q) - W_DEQUE_START(Q)                          \
            )                                                              \
        )                                                                  \
    ))                                                                     \
    /**/

/***
 *** Name:        W_DEQUE_GET_SIZE
 *** Proto:       W_DEQUE_GET_SIZE(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_GET_SIZE to get the number of elements in a deque. If Q is NULL, the size is zero.
 ***/
#define W_DEQUE_GET_SIZE(Q)                                                \
    ((Q) == NULL ? 0 : W_DEQUE_SIZE(Q))                                    \
    /**/

/***
 *** Name:        W_DEQUE_IS_EMPTY
 *** Proto:       W_DEQUE_IS_EMPTY(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_IS_EMPTY to test if a deque is empty.
 ***/
#define W_DEQUE_IS_EMPTY(Q)                                                \
    ( (Q) == NULL || (W_DEQUE_END(Q) == W_DEQUE_START(Q)) )                \
    /**/

/***
 *** Name:        W_DEQUE_POP_FRONT
 *** Proto:       W_DEQUE_POP_FRONT(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP_FRONT to get pop an element from the front of a deque.
 ***/
#define W_DEQUE_POP_FRONT(Q,element)                                       \
    ((element) = (Q)[W_DEQUE_START(Q) & (W_DEQUE_ALLOC_SIZE(Q) - 1)],      \
    W_DEQUE_START(Q) = (W_DEQUE_START(Q) + 1) &                            \
            ((W_DEQUE_ALLOC_SIZE(Q) << 1) - 1 ),                            \
    (element))                                                             \
    /**/


/***
 *** Name:        W_DEQUE_POP_BACK
 *** Proto:       W_DEQUE_POP_BACK(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP_BACK to get pop an element from the back of a deque.
 ***/
#define W_DEQUE_POP_BACK(Q,element)                                        \
    ((element) = (Q)[(W_DEQUE_END(Q) - 1) & (W_DEQUE_ALLOC_SIZE(Q) - 1)],  \
    W_DEQUE_END(Q) = (W_DEQUE_END(Q) - 1) &                                \
            ((W_DEQUE_ALLOC_SIZE(Q) << 1) - 1),                            \
    (element))                                                             \
    /**/


/***
 *** Name:        W_DEQUE_POP
 *** Proto:       W_DEQUE_POP(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP to get pop an element from a deque.
 ***/
#define W_DEQUE_POP(Q,element)                                             \
    W_DEQUE_POP_FRONT(Q,element)                                           \
    /**/

#define W_DEQUE_PUSH(Q,...)                                                \
    W_DEQUE_PUSH_BACK(Q,__VA_ARGS__)                                       \
    /**/


/***
 *** Name:        W_DEQUE_PUSH_BACK
 *** Proto:       W_DEQUE_PUSH_BACK(Q,...)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         ...      elements to be pushed to the queue
 *** Description: Use W_DEQUE_PUSH_BACK to push elements back of a deque. The expression return NULL if the queue is full, the queue itself otherwise.
 ***/
#define W_DEQUE_PUSH_BACK(Q,...)                                           \
    ( (Q) != NULL &&                                                       \
            W_DEQUE_HAS_SPACE(Q, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)) ?    \
        ( BOOST_PP_SEQ_FOR_EACH(                                           \
                _W_DEQUE_PUSH_BACK,                                        \
                Q,                                                         \
                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) Q) :                \
        NULL )                                                             \
    /**/

#define _W_DEQUE_PUSH_BACK(r,Q,item)                                       \
    ( (Q)[W_DEQUE_END(Q) & (W_DEQUE_ALLOC_SIZE(Q) - 1)] = (item) ),        \
    ( W_DEQUE_END(Q) = (W_DEQUE_END(Q) + 1) &                              \
            ((W_DEQUE_ALLOC_SIZE(Q) << 1) - 1) ),                          \
    /**/

/***
 *** Name:        W_DEQUE_PUSH_FRONT
 *** Proto:       W_DEQUE_PUSH_FRONT(Q,...)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         ...      elements to be pushed to the queue
 *** Description: Use W_DEQUE_PUSH_FRONT to push elements front of a deque. If queue is full, NULL is returned.
 ***/
#define W_DEQUE_PUSH_FRONT(Q,...)                                          \
    ( (Q) != NULL &&                                                       \
            W_DEQUE_HAS_SPACE(Q, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)) ?    \
        ( BOOST_PP_SEQ_FOR_EACH(                                           \
                _W_DEQUE_PUSH_FRONT,                                       \
                Q,                                                         \
                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) Q) :                \
        NULL )                                                             \
    /**/

#define _W_DEQUE_PUSH_FRONT(r,Q,item)                                      \
    ( (Q)[(W_DEQUE_START(Q) - 1) & (W_DEQUE_ALLOC_SIZE(Q) - 1)] =          \
            (item) ),                                                      \
    ( W_DEQUE_START(Q) = (W_DEQUE_START(Q) - 1) &                          \
            ((W_DEQUE_ALLOC_SIZE(Q) << 1) - 1) ),                          \
    /**/


/***
 *** Name:        W_DEQUE_CLEAR
 *** Proto:       W_DEQUE_CLEAR(Q)
 *** Arg:         Q        a pointer to a deque.
 *** Description: Use W_DEQUE_CLEAR to clear a deque (without freeing it).
 ***/
#define W_DEQUE_CLEAR(Q)                                                   \
    (W_DEQUE_START(Q) = W_DEQUE_END(Q) = 0)


#define W_DEQUE_ALLOC_SIZE_BYTES(Q,size_lg2)                               \
    (sizeof(W_DEQUE_HEADER_TYPE) + W_DEQUE_ELEM_SIZE(Q) * (1 <<            \
                                                           (size_lg2)))    \
    /**/


/***
 *** Name:        W_DEQUE_FOR_EACH
 *** Proto:       W_DEQUE_FOR_EACH(T,e,Q)
 *** Arg:         T           a type name.
 *** Arg:         e           a free identifier
 *** Arg:         Q           a pointer to a deque.
 *** Description: Use W_DEQUE_FOR_EACH to iterate all elements in a deque.
 *** Example:     'W_DEQUE_FOR_EACH(int,x,deque) printf("%d\n", x);'.
 ***/
#define W_DEQUE_FOR_EACH(T,e,Q)                                            \
   W_DECLARE(1, T e)                                                       \
   for (unsigned W_CAT(e,_ix) = 0, W_CAT(e,_size)=W_DEQUE_SIZE(Q);         \
       W_CAT(e,_ix) < W_CAT(e,_size)                                       \
           && (e = W_DEQUE_PEEK_FRONT(Q, W_CAT(e,_ix)), 1);                \
       ++W_CAT(e,_ix))

/***
 *** Name:        W_DEQUE_FOR_EACH_REVERSED
 *** Proto:       W_DEQUE_FOR_EACH_REVERSED(T,e,Q)
 *** Arg:         T           a type name.
 *** Arg:         e           a free identifier
 *** Arg:         Q           a pointer to a deque.
 *** Description: Use W_DEQUE_FOR_EACH_REVERSED to iterate all elements in a deque in reversed order.
 *** Example:     'W_DEQUE_FOR_EACH_REVERSED(int,x,deque) printf("%d\n", x);'.
 ***/
#define W_DEQUE_FOR_EACH_REVERSED(T,e,Q)                                   \
   W_DECLARE(1, T e)                                                       \
   for (unsigned W_CAT(e,_ix) = 0;                                         \
       W_CAT(e,_ix) < W_DEQUE_SIZE(Q)                                      \
           && (e = W_DEQUE_PEEK_BACK(Q, W_CAT(e,_ix)), 1);                 \
       ++W_CAT(e,_ix))


/***
 *** Name:        W_DEQUE_PEEK
 *** Proto:       W_DEQUE_PEEK(Q[,n])
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         n           index starting from the front of the queue.
 *** Description: Use W_DEQUE_PEEK to peek an element in deque.
 ***/
#define W_DEQUE_PEEK(...)                                                  \
    W_DEQUE_PEEK_FRONT(__VA_ARGS__)                                        \
    /**/


/***
 *** Name:        W_DEQUE_PEEK_FRONT
 *** Proto:       W_DEQUE_PEEK_FRONT(Q[,n])
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         n           index starting from the front of the queue.
 *** Description: Use W_DEQUE_PEEK_FRONT to peek an element in deque.
 ***/
#define W_DEQUE_PEEK_FRONT(...)                                            \
    BOOST_PP_OVERLOAD(_W_DEQUE_PEEK_FRONT_,__VA_ARGS__)(__VA_ARGS__)

/***
 *** Name:        W_DEQUE_PEEK_BACK
 *** Proto:       W_DEQUE_PEEK_BACK(Q[,n])
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         n           index starting from the back of the queue.
 *** Description: Use W_DEQUE_PEEK_BACK to peek an element in deque.
 ***/
#define W_DEQUE_PEEK_BACK(...)                                             \
    BOOST_PP_OVERLOAD(_W_DEQUE_PEEK_BACK_,__VA_ARGS__)(__VA_ARGS__)

#define _W_DEQUE_PEEK_FRONT_1(Q) _W_DEQUE_PEEK_FRONT_2(Q,0)
#define _W_DEQUE_PEEK_BACK_1(Q) _W_DEQUE_PEEK_BACK_2(Q,0)

#define _W_DEQUE_PEEK_FRONT_2(Q,n)                                         \
    (Q)[(W_DEQUE_START(Q) + (n)) & (W_DEQUE_ALLOC_SIZE(Q) - 1)]

#define _W_DEQUE_PEEK_BACK_2(Q,n)                                          \
    (Q)[(W_DEQUE_END(Q) - (n) - 1) & (W_DEQUE_ALLOC_SIZE(Q) - 1)]

#define W_DEQUE_HAS_SPACE(Q,n)                                             \
    (W_DEQUE_SIZE(Q) + (n) <= W_DEQUE_ALLOC_SIZE(Q))


#ifndef W_TEST
# define W_TEST(...)
#endif

#ifndef W_TEST_GROUP
# define W_TEST_GROUP(...)
#endif

W_TEST_GROUP("Deque")

W_TEST(W_DEQUE_INIT,
    int* deque;
    W_DEQUE_INIT(deque, 3);
    W_TEST_ASSERT(W_DEQUE_GET_SIZE(deque) == 0, "Deque size mismatch");
    W_DEQUE_FREE(deque);
)

W_TEST(W_DEQUE_PUSH_BACK,
    int* deque = NULL;
    W_DEQUE_INIT(deque, 3);
    W_TEST_ASSERT(W_DEQUE_PUSH_BACK(deque, 1), "deque is full");
    W_TEST_ASSERT(W_DEQUE_PUSH_BACK(deque, 2), "deque is full");
    W_TEST_ASSERT(W_DEQUE_GET_SIZE(deque) == 2, "Deque size mismatch");

    int elem;
    W_DEQUE_POP_FRONT(deque,elem);
    W_TEST_ASSERT(elem == 1, "Deque value mismatch: %d (not 1)", elem);
    W_DEQUE_POP_FRONT(deque,elem);
    W_TEST_ASSERT(elem == 2, "Deque value mismatch: %d (not 2)", elem);
    W_TEST_ASSERT(W_DEQUE_GET_SIZE(deque) == 0, "Deque size mismatch");

    W_DEQUE_FREE(deque);
)

W_TEST(W_DEQUE_PUSH_FRONT,
    int* deque;
    W_DEQUE_INIT(deque, 3);
    W_TEST_ASSERT(W_DEQUE_PUSH_FRONT(deque, 1), "deque is full");
    W_TEST_ASSERT(W_DEQUE_PUSH_FRONT(deque, 2), "deque is full");
    W_TEST_ASSERT(W_DEQUE_GET_SIZE(deque) == 2, "Deque size mismatch");

    int elem;
    W_DEQUE_POP_FRONT(deque,elem);
    W_TEST_ASSERT(elem == 2, "Deque value mismatch: %d (not 2)", elem);
    W_DEQUE_POP_FRONT(deque,elem);
    W_TEST_ASSERT(elem == 1, "Deque value mismatch: %d (not 1)", elem);
    W_TEST_ASSERT(W_DEQUE_GET_SIZE(deque) == 0, "Deque size mismatch");

    W_DEQUE_FREE(deque);
)

#endif
