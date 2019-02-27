/* (C) Copyright 2018,2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_DYNAMIC_ARRAY_H
#define __W_DYNAMIC_ARRAY_H

#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>

#include <wondermacros/pointer/hidden_of.h>
#include <wondermacros/array/move_left.h>


#ifndef W_MALLOC
# define W_MALLOC malloc
#endif

#ifndef W_REALLOC
# define W_REALLOC realloc
#endif

#ifndef W_FREE
# define W_FREE free
#endif

#ifndef W_ERROR_ALLOCATION
# define W_ERROR_ALLOCATION                                                   \
    do {                                                                      \
        fprintf(stderr, "Unable to allocate memory for dynamic array.\n");    \
        exit(1);                                                              \
    } while (0)
#endif


#define W_DYNAMIC_ARRAY_HEADER_TYPE                                           \
    struct {                                                                  \
        int alloc_size;                                                       \
        int nbr_of_elems;                                                     \
    }


/***
 *** Name:        W_DYNAMIC_ARRAY_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_SIZE(array)
 ***
 *** Arg:         array   A pointer to a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_SIZE to get the number of elements in the array.
 ***/
#define W_DYNAMIC_ARRAY_SIZE(array) \
    W_HIDDEN_OF(array,W_DYNAMIC_ARRAY_HEADER_TYPE,nbr_of_elems)
#define W_DYNAMIC_ARRAY_GET_SIZE(array) \
    ((array) == NULL ? 0 : W_HIDDEN_OF(array,W_DYNAMIC_ARRAY_HEADER_TYPE,nbr_of_elems))

/***
 *** Name:        W_DYNAMIC_ARRAY_ALLOC_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_ALLOC_SIZE(array)
 ***
 *** Arg:         array   A pointer to an array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_ALLOC_SIZE to get the current allocation size.
 ***/
#define W_DYNAMIC_ARRAY_ALLOC_SIZE(array) \
    W_HIDDEN_OF(array,W_DYNAMIC_ARRAY_HEADER_TYPE,alloc_size)

/***
 *** Name:        W_DYNAMIC_ARRAY_STEAL_LAST
 *** Proto:       W_DYNAMIC_ARRAY_STEAL_LAST(array)
 ***
 *** Arg:         array   array  A pointer to a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_STEAL_LAST to get and remove the last element in the array.
 *** Notes:       If the array is empty, the behaviour is undefined.
 ***/
#define W_DYNAMIC_ARRAY_STEAL_LAST(array) ((array)[--W_DYNAMIC_ARRAY_SIZE(array)])

/***
 *** Name:        W_DYNAMIC_ARRAY_PEEK_LAST
 *** Proto:       W_DYNAMIC_ARRAY_PEEK_LAST(array)
 ***
 *** Arg:         array   array  A pointer to a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_PEEK_LAST to get the last element in the array.
 *** Notes:       If the array is empty, the behaviour is undefined.
 ***/
#define W_DYNAMIC_ARRAY_PEEK_LAST(array) ((array)[W_DYNAMIC_ARRAY_SIZE(array)-1])

/***
 *** Name:        W_DYNAMIC_ARRAY_PEEK_LAST_SAFE
 *** Proto:       W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(array,value)
 ***
 *** Arg:         array   array    A pointer to a dynamic array
 *** Arg:         value   a value  A value returned if the array is empty
 ***
 *** Description: Use W_DYNAMIC_ARRAY_PEEK_LAST_SAFE to get the last element in the array.
 ***              If the array is empty, the given value is returned.
 ***/
#define W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(array,value) \
    (W_DYNAMIC_ARRAY_SIZE(array) == 0 ? (value) : (array)[W_DYNAMIC_ARRAY_SIZE(array)-1])

/***
 *** Name:        W_DYNAMIC_ARRAY_INIT
 *** Proto:       W_DYNAMIC_ARRAY_INIT(name,T,init_size)
 ***
 *** Arg:         array      Array pointer
 *** Arg:         init_size  Initial allocation size for the array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_INIT to initialize a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_INIT(array,init_size)                                              \
    do {                                                                                   \
        (array) = W_MALLOC(sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE) + (init_size) * sizeof((array)[0])); \
        if ((array) == NULL)                                                               \
            W_ERROR_ALLOCATION;                                                            \
        array = W_REF_VOID_PTR(array,sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE));                 \
        W_HIDDEN_OF(array, W_DYNAMIC_ARRAY_HEADER_TYPE, alloc_size) = (init_size);         \
        W_HIDDEN_OF(array, W_DYNAMIC_ARRAY_HEADER_TYPE, nbr_of_elems) = 0;                 \
    } while (0)

/***
 *** Name:        W_DYNAMIC_ARRAY_FREE
 *** Proto:       W_DYNAMIC_ARRAY_FREE(array)
 ***
 *** Arg:         array      a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_FREE to free a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_FREE(array)                                            \
    do {                                                                       \
        if (!(array))                                                          \
            break;                                                             \
        W_FREE(W_HIDDEN_CONTAINER_OF(array,W_DYNAMIC_ARRAY_HEADER_TYPE));      \
        (array) = NULL;                                                        \
    } while (0)


#define _W_DYNAMIC_ARRAY_PUSH(r,array,i,e)                                      \
    (array)[W_DYNAMIC_ARRAY_SIZE(array) + i] = e;

/***
 *** Name:        W_DYNAMIC_ARRAY_PUSH
 *** Proto:       W_DYNAMIC_ARRAY_PUSH(array,...)
 ***
 *** Arg:         array      Array pointer
 *** Arg:         ...        Values to be pushed into a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_PUSH to add values to a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_PUSH(array,...)                                                \
    do {                                                                               \
        if ((array) == NULL)                                                           \
            W_DYNAMIC_ARRAY_INIT(array, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__));          \
        while (W_DYNAMIC_ARRAY_ALLOC_SIZE(array) - W_DYNAMIC_ARRAY_SIZE(array) <       \
            BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))                                       \
            W_DYNAMIC_ARRAY_GROW(array);                                               \
        BOOST_PP_SEQ_FOR_EACH_I(_W_DYNAMIC_ARRAY_PUSH,array,                           \
            BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))                                     \
        W_DYNAMIC_ARRAY_SIZE(array) += BOOST_PP_VARIADIC_SIZE(__VA_ARGS__);            \
    } while (0)

/***
 *** Name:        W_DYNAMIC_ARRAY_REMOVE
 *** Proto:       W_DYNAMIC_ARRAY_REMOVE(array,pos[,nbr_of_elems])
 ***
 *** Arg:         array         Array pointer
 *** Arg:         pos           Array index
 *** Arg:         nbr_of_elems  Number of elements to be removed (default is one).
 ***
 *** Description: Use W_DYNAMIC_ARRAY_REMOVE to remove elements from a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_REMOVE(array,...) \
    BOOST_PP_OVERLOAD(_W_DYNAMIC_ARRAY_REMOVE_,__VA_ARGS__)(array,__VA_ARGS__)

#define _W_DYNAMIC_ARRAY_REMOVE_1(array,pos) _W_DYNAMIC_ARRAY_REMOVE_2(array,pos,1)
#define _W_DYNAMIC_ARRAY_REMOVE_2(array,pos,nbr_of_elems)                     \
    do {                                                                      \
        int W_ID(e) = (nbr_of_elems);                                         \
        W_ARRAY_MOVE_LEFT(array,W_DYNAMIC_ARRAY_SIZE(array),pos,W_ID(e));     \
        W_DYNAMIC_ARRAY_SIZE(array) -= W_ID(e);                               \
    } while (0)

#define W_DYNAMIC_ARRAY_GROW(array)                                                    \
    do {                                                                               \
        W_DYNAMIC_ARRAY_ALLOC_SIZE(array) = W_DYNAMIC_ARRAY_ALLOC_SIZE(array) ?        \
            (W_DYNAMIC_ARRAY_ALLOC_SIZE(array) << 1) : 8;                              \
        array = W_REALLOC(W_HIDDEN_CONTAINER_OF(array,W_DYNAMIC_ARRAY_HEADER_TYPE),    \
            sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE) +                                      \
            W_DYNAMIC_ARRAY_ALLOC_SIZE(array) * sizeof((array)[0]));                   \
        if ((array) == NULL)                                                           \
            W_ERROR_ALLOCATION;                                                        \
        array = W_REF_VOID_PTR(array,sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE));             \
    } while (0)


#include <wondermacros/array/for_each.h>

#define W_DYNAMIC_ARRAY_FOR_EACH(T,elem,array)                                         \
    for (void* W_ID(a) = (array); W_ID(a); W_ID(a) = NULL)                             \
        W_ARRAY_FOR_EACH(T,elem,array,W_DYNAMIC_ARRAY_GET_SIZE(array))

#define W_DYNAMIC_ARRAY_FOR_EACH_PTR(T,elemp,array)                                    \
    W_ARRAY_FOR_EACH_PTR(T,elemp,array,W_DYNAMIC_ARRAY_GET_SIZE(array))


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

#ifndef W_TEST_GROUP
# define W_TEST_GROUP(...)
#endif

W_TEST_GROUP("Dynamic Array")

W_TEST(W_DYNAMIC_ARRAY_PUSH,
    int* array = NULL;
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2);
    W_TEST_ASSERT(W_DYNAMIC_ARRAY_GET_SIZE(array) == 2, "Array size mismatch");

    W_DYNAMIC_ARRAY_FREE(array);
)

W_TEST(W_DYNAMIC_ARRAY_STEAL_LAST,
    int* array = NULL;
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4);
    W_TEST_ASSERT(W_DYNAMIC_ARRAY_STEAL_LAST(array) == 4, "Steal last failed");
    W_TEST_ASSERT(W_DYNAMIC_ARRAY_GET_SIZE(array) == 3, "Array size mismatch");

    W_DYNAMIC_ARRAY_FREE(array);
)

#endif
