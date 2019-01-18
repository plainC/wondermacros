/* (C) is Copyright 2018,2019 J.P. Iivonen <wondermacros@yahoo.com>
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
#include <wondermacros/compiler/hidden_of.h>
#include <wondermacros/meta/id.h>
#include <wondermacros/meta/declare.h>
#include <wondermacros/meta/wrap.h>


#ifndef W_MALLOC
# include <stdlib.h>
# define W_MALLOC(size) malloc(size)
#endif

#ifndef W_MALLOC0
# include <string.h>
# define W_MALLOC0(size) memset(malloc(size), 0, size)
#endif

#ifndef W_REALLOC
# define W_REALLOC realloc
#endif

#ifndef W_FREE
# define W_FREE free
#endif

#ifndef W_ERROR_ALLOCATION
# define W_ERROR_ALLOCATION                                                      \
    do {                                                                         \
        fprintf(stderr, "Unable to allocate memory.\n");                         \
        exit(1);                                                                 \
    } while (0)
#endif


#ifndef WDEBUG_EXPAND
#define W_DEQUE_HEADER_TYPE    \
    struct {                   \
        unsigned alloc_size;   \
        unsigned start;        \
        unsigned end;          \
    }
#endif

#define W_DEQUE_ALLOC_SIZE_POW2(deque)                                           \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, alloc_size)
#define W_DEQUE_ALLOC_SIZE(deque)                                                \
    (0x1U << W_DEQUE_ALLOC_SIZE_POW2(deque))
#define W_DEQUE_START(deque)                                                     \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, start)
#define W_DEQUE_END(deque)                                                       \
    W_HIDDEN_OF(deque, W_DEQUE_HEADER_TYPE, end)

/***
 *** Name:        W_DEQUE_FREE
 *** Proto:       W_DEQUE_FREE(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_FREE to free a deque.
 ***/
#define W_DEQUE_FREE(Q)                                                          \
    W_FREE(W_HIDDEN_CONTAINER_OF(Q, W_DEQUE_HEADER_TYPE))

#define W_DEQUE_IS_ALLOC_FULL(Q)                                                 \
    (W_DEQUE_END(Q) == (W_DEQUE_START(Q) ^ W_DEQUE_ALLOC_SIZE(Q)))

#define W_DEQUE_ELEM_SIZE(Q)                                                     \
    sizeof((Q)[0])

/***
 *** Name:        W_DEQUE_SIZE
 *** Proto:       W_DEQUE_SIZE(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_SIZE to get the number of elements in a deque.
 ***/
#define W_DEQUE_SIZE(Q) (                                                        \
    W_DEQUE_IS_ALLOC_FULL (Q) ? (                                                \
        W_DEQUE_ALLOC_SIZE (Q)                                                   \
    ) : (                                                                        \
        (W_DEQUE_START (Q) <= W_DEQUE_ALLOC_SIZE (Q)) ? (                        \
            (W_DEQUE_END (Q) <= W_DEQUE_ALLOC_SIZE (Q)) ? (                      \
                (W_DEQUE_END (Q) - W_DEQUE_START (Q))                            \
            ) : (                                                                \
                (W_DEQUE_END(Q) - W_DEQUE_START(Q)) & (W_DEQUE_ALLOC_SIZE(Q)-1)  \
            )                                                                    \
        ) : (                                                                    \
            W_DEQUE_END (Q) <= W_DEQUE_ALLOC_SIZE (Q) ? (                        \
                (W_DEQUE_END(Q) - W_DEQUE_START(Q)) & (W_DEQUE_ALLOC_SIZE(Q)-1)  \
            ) : (                                                                \
                W_DEQUE_END (Q) - W_DEQUE_START (Q)                              \
            )                                                                    \
        )                                                                        \
    ))                                                                           \

/***
 *** Name:        W_DEQUE_IS_EMPTY
 *** Proto:       W_DEQUE_IS_EMPTY(Q)
 *** Arg:         Q  a pointer to a deque.
 *** Description: Use W_DEQUE_IS_EMPTY to test if a deque is empty.
 ***/
#define W_DEQUE_IS_EMPTY(Q)                                                      \
    (W_DEQUE_END(Q) == W_DEQUE_START(Q))

/***
 *** Name:        W_DEQUE_POP_FRONT
 *** Proto:       W_DEQUE_POP_FRONT(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP_FRONT to get pop an element from the front of a deque.
 ***/
#define W_DEQUE_POP_FRONT(Q,element)                                             \
    ((element) = (Q)[W_DEQUE_START(Q) & (W_DEQUE_ALLOC_SIZE(Q) - 1)],            \
    W_DEQUE_START(Q) = (W_DEQUE_START(Q) + 1) & (2 * W_DEQUE_ALLOC_SIZE(Q) - 1), \
    (element))

/***
 *** Name:        W_DEQUE_POP_BACK
 *** Proto:       W_DEQUE_POP_BACK(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP_BACK to get pop an element from the back of a deque.
 ***/
#define W_DEQUE_POP_BACK(Q,element)                                              \
    ((element) = (Q)[(_DEQUE_END(Q) - 1) & (DEQUE_ALLOC_SIZE(Q) - 1)],           \
    _DEQUE_END(Q) = (_DEQUE_END(Q) - 1) & (2 * DEQUE_ALLOC_SIZE(Q) - 1),         \
    (element))

/***
 *** Name:        W_DEQUE_POP
 *** Proto:       W_DEQUE_POP(Q,element)
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         element  an identifier where the fetched element is stored
 *** Description: Use W_DEQUE_POP to get pop an element from a deque.
 ***/
#define W_DEQUE_POP(Q,element)                                                   \
    W_DEQUE_POP_FRONT(Q,element)

/***
 *** Name:        W_DEQUE_PUSH_BACK
 *** Proto:       W_DEQUE_PUSH_BACK(is_full,Q,...)
 *** Arg:         is_full  an integer variable to be assigned.
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         ...      elements to be pushed to the queue
 *** Description: Use W_DEQUE_PUSH_BACK to push elements back of a deque. 'is_full' is assigned 1 if queue is full.
 ***/
#define W_DEQUE_PUSH_BACK(is_full,Q,...)                                         \
    W_WRAP(W_DEQUE_PUSH_BACK,                                                    \
        if (0 == ((is_full) = (((Q) == NULL)                                     \
            || (!W_DEQUE_HAS_SPACE(Q, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)))))) { \
            BOOST_PP_SEQ_FOR_EACH(_W_DEQUE_PUSH_BACK,Q,                          \
                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))                           \
        }                                                                        \
    )

#define _W_DEQUE_PUSH_BACK(r,Q,item)                                             \
    (Q)[W_DEQUE_END(Q) & (W_DEQUE_ALLOC_SIZE(Q) - 1)] = (item);                  \
    W_DEQUE_END(Q) = (W_DEQUE_END(Q) + 1) & (2 * W_DEQUE_ALLOC_SIZE(Q) - 1);

/***
 *** Name:        W_DEQUE_PUSH_FRONT
 *** Proto:       W_DEQUE_PUSH_FRONT(is_full,Q,...)
 *** Arg:         is_full  an integer variable to be assigned.
 *** Arg:         Q        a pointer to a deque.
 *** Arg:         ...      elements to be pushed to the queue
 *** Description: Use W_DEQUE_PUSH_FRONT to push elements front of a deque. 'is_full' is assigned 1 if queue is full.
 ***/
#define W_DEQUE_PUSH_FRONT(is_full,Q,...)                                        \
    W_WRAP(W_DEQUE_PUSH_FRONT,                                                   \
        if (0 == ((is_full) = (((Q) == NULL)                                     \
            || (!W_DEQUE_HAS_SPACE(Q, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)))))) { \
            BOOST_PP_SEQ_FOR_EACH(_W_DEQUE_PUSH_FRONT,Q,                         \
                BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))                           \
        }                                                                        \
    )

#define _W_DEQUE_PUSH_FRONT(r,Q,element)                                         \
    (Q)[(W_DEQUE_START(Q) - 1) & (W_DEQUE_ALLOC_SIZE(Q) - 1)] = (element);       \
    W_DEQUE_START(Q) = (W_DEQUE_START(Q) - 1) & (2 * W_DEQUE_ALLOC_SIZE(Q) - 1);

/***
 *** Name:        W_DEQUE_CLEAR
 *** Proto:       W_DEQUE_CLEAR(Q)
 *** Arg:         Q        a pointer to a deque.
 *** Description: Use W_DEQUE_CLEAR to clear a deque (without freeing it).
 ***/
#define W_DEQUE_CLEAR(Q)                                                         \
    (W_DEQUE_START(Q) = W_DEQUE_END(Q) = 0)


#define W_DEQUE_ALLOC_SIZE_BYTES(Q,size_pow2)                                    \
    (sizeof(W_DEQUE_HEADER_TYPE) + W_DEQUE_ELEM_SIZE(Q) * (1 << (size_pow2)))

/***
 *** Name:        W_DEQUE_INIT
 *** Proto:       W_DEQUE_INIT(Q,alloc_size)
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         alloc_size  exponent of two
 *** Description: Use W_DEQUE_INIT to initialize a deque. The size is given as a power of two (i.g. 4 means size 16).
 ***/
#define W_DEQUE_INIT(Q,init_size)                                                \
    W_WRAP(W_DEQUE_INIT,                                                         \
        unsigned W_ID(size) = (init_size);                                       \
        (Q) = W_MALLOC(W_DEQUE_ALLOC_SIZE_BYTES(Q,W_ID(size)));                  \
        if ((Q) == NULL)                                                         \
            W_ERROR_ALLOCATION;                                                  \
        (Q) = W_REF_VOID_PTR(Q, sizeof(W_DEQUE_HEADER_TYPE));                    \
        W_DEQUE_ALLOC_SIZE_POW2(Q) = W_ID(size);                                 \
        W_DEQUE_CLEAR(Q);                                                        \
    )

/***
 *** Name:        W_DEQUE_FOR_EACH
 *** Proto:       W_DEQUE_FOR_EACH(T,e,Q)
 *** Arg:         T           a type name.
 *** Arg:         e           a free identifier
 *** Arg:         Q           a pointer to a deque.
 *** Description: Use W_DEQUE_FOR_EACH to iterate all elements in a deque.
 *** Example:     'W_DEQUE_FOR_EACH(int,x,deque) printf("%d\n", x);'.
 ***/
#define W_DEQUE_FOR_EACH(T,e,Q)                                                  \
   W_DECLARE(1, T e)                                                             \
   for (unsigned W_CAT(e,_ix) = 0;                                               \
       W_CAT(e,_ix) < W_DEQUE_SIZE(Q)                                            \
           && (e = W_DEQUE_PEEK_FRONT(Q, W_CAT(e,_ix)), 1);                      \
       ++W_CAT(e,_ix))

/***
 *** Name:        W_DEQUE_FOR_EACH_REVERSED
 *** Proto:       W_DEQUE_FOR_EACH_REVERSED(T,e,Q)
 *** Arg:         T           a type name.
 *** Arg:         e           a free identifier
 *** Arg:         Q           a pointer to a deque.
 *** Description: Use W_DEQUE_FOR_EACH to iterate all elements in a deque in reversed order.
 *** Example:     'W_DEQUE_FOR_EACH(int,x,deque) printf("%d\n", x);'.
 ***/
#define W_DEQUE_FOR_EACH_REVERSED(T,e,Q)                                         \
   W_DECLARE(1, T e)                                                             \
   for (unsigned W_CAT(e,_ix) = 0;                                               \
       W_CAT(e,_ix) < W_DEQUE_SIZE(Q)                                            \
           && (e = W_DEQUE_PEEK_BACK(Q, W_CAT(e,_ix)), 1);                       \
       ++W_CAT(e,_ix))


/***
 *** Name:        W_DEQUE_PEEK_FRONT
 *** Proto:       W_DEQUE_PEEK_FRONT(Q[,n])
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         n           index starting from the front of the queue.
 *** Description: Use W_DEQUE_PEEK_FRONT to peek an element in deque.
 ***/
#define W_DEQUE_PEEK_FRONT(...)                                                  \
    BOOST_PP_OVERLOAD(_W_DEQUE_PEEK_FRONT_,__VA_ARGS__)(__VA_ARGS__)

/***
 *** Name:        W_DEQUE_PEEK_BACK
 *** Proto:       W_DEQUE_PEEK_BACK(Q[,n])
 *** Arg:         Q           a pointer to a deque.
 *** Arg:         n           index starting from the back of the queue.
 *** Description: Use W_DEQUE_PEEK_BACK to peek an element in deque.
 ***/
#define W_DEQUE_PEEK_BACK(...)                                                   \
    BOOST_PP_OVERLOAD(_W_DEQUE_PEEK_BACK_,__VA_ARGS__)(__VA_ARGS__)

#define _W_DEQUE_PEEK_FRONT_1(Q) _W_DEQUE_PEEK_FRONT_2(Q,0)
#define _W_DEQUE_PEEK_BACK_1(Q) _W_DEQUE_PEEK_BACK_2(Q,0)

#define _W_DEQUE_PEEK_FRONT_2(Q,n)                                               \
    (Q)[(W_DEQUE_START(Q) + (n)) & (W_DEQUE_ALLOC_SIZE(Q) - 1)]

#define _W_DEQUE_PEEK_BACK_2(Q,n)                                                \
    (Q)[(W_DEQUE_END(Q) - (n) - 1) & (W_DEQUE_ALLOC_SIZE(Q) - 1)]

#define W_DEQUE_HAS_SPACE(Q,n)                                                   \
    (W_DEQUE_SIZE(Q) + (n) <= W_DEQUE_ALLOC_SIZE(Q))


#endif

