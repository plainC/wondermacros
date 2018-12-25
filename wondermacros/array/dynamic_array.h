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

#ifndef __W_DYNAMIC_ARRAY_H
#define __W_DYNAMIC_ARRAY_H

#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>

#include <wondermacros/compiler/ref_void_ptr.h>

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
        int elem_size;                                                        \
    }


#define W_DYNAMIC_ARRAY_HEADER(array)                                         \
    ((W_DYNAMIC_ARRAY_HEADER_TYPE*) W_REF_VOID_PTR(array, -sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE)))

/***
 *** Name:        W_DYNAMIC_ARRAY_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_SIZE(array)
 ***
 *** Arg:         array   array  A pointer to an array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_SIZE to get the number of elements in the array.
 ***/
#define W_DYNAMIC_ARRAY_SIZE(array) (W_DYNAMIC_ARRAY_HEADER(array)->nbr_of_elems)

/***
 *** Name:        W_DYNAMIC_ARRAY_ALLOC_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_ALLOC_SIZE(array)
 ***
 *** Arg:         array   array  A pointer to an array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_ALLOC_SIZE to get the current allocation size.
 ***/
#define W_DYNAMIC_ARRAY_ALLOC_SIZE(array) (W_DYNAMIC_ARRAY_HEADER(array)->alloc_size)

/***
 *** Name:        W_DYNAMIC_ARRAY_ELEM_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_ELEM_SIZE(array)
 ***
 *** Arg:         array   array  A pointer to an array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_ELEM_SIZE to get the element size.
 ***/
#define W_DYNAMIC_ARRAY_ELEM_SIZE(array) (W_DYNAMIC_ARRAY_HEADER(array)->elem_size)

/***
 *** Name:        W_DYNAMIC_ARRAY_INIT
 *** Proto:       W_DYNAMIC_ARRAY_INIT(name,T,init_size)
 ***
 *** Arg:         name      array name  Array name
 *** Arg:         T         type name   Type name of array elements
 *** Arg:         init_size size        Initial allocation size for the array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_INIT to initialize a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_INIT(name,elem_type,init_size)                                  \
    _W_DYNAMIC_ARRAY_INIT(name,sizeof(elem_type),init_size)

#define _W_DYNAMIC_ARRAY_INIT(name,elem_size,init_size)                                 \
    do {                                                                                \
        name = W_MALLOC(sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE) + (init_size) * elem_size); \
        if (name == NULL)                                                               \
            W_ERROR_ALLOCATION;                                                         \
        name = W_REF_VOID_PTR(name,sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE));                \
        W_DYNAMIC_ARRAY_ALLOC_SIZE(name) = (init_size);                                 \
        W_DYNAMIC_ARRAY_ELEM_SIZE(name) = elem_size;                                    \
        W_DYNAMIC_ARRAY_SIZE(name) = 0;                                                 \
    } while (0)

/***
 *** Name:        W_DYNAMIC_ARRAY_CLEAR
 *** Proto:       W_DYNAMIC_ARRAY_CLEAR(name)
 ***
 *** Arg:         name      array name  Array name
 ***
 *** Description: Use W_DYNAMIC_ARRAY_CLEAR to clear a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_CLEAR(name)                                           \
    do {                                                                      \
        int W_ID(elem_size) W_DYNAMIC_ARRAY_ELEM_SIZE(name);                  \
        W_FREE(W_DYNAMIC_ARRAY_HEADER(name));                                 \
        _W_DYNAMIC_ARRAY_INIT(name,W_ID(elem_size),0);                        \
    } while (0)

#define W_DYNAMIC_ARRAY_FREE(name)                                            \
    W_FREE(W_DYNAMIC_ARRAY_HEADER(name))


#define _W_DYNAMIC_ARRAY_PUSH(r,name,i,e)                                     \
    (name)[W_DYNAMIC_ARRAY_SIZE(name) + i] = e;

/***
 *** Name:        W_DYNAMIC_ARRAY_PUSH
 *** Proto:       W_DYNAMIC_ARRAY_PUSH(name,...)
 ***
 *** Arg:         name      array name  Array name
 *** Arg:         ...       values      Values to be pushed into a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_PUSH to add values to a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_PUSH(name,...)                                           \
    do {                                                                         \
        while (W_DYNAMIC_ARRAY_ALLOC_SIZE(name) - W_DYNAMIC_ARRAY_SIZE(name) <   \
            BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))                                 \
            W_DYNAMIC_ARRAY_GROW(name);                                          \
        BOOST_PP_SEQ_FOR_EACH_I(_W_DYNAMIC_ARRAY_PUSH,name,                      \
            BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))                               \
        W_DYNAMIC_ARRAY_SIZE(name) += BOOST_PP_VARIADIC_SIZE(__VA_ARGS__);       \
    } while (0)

#define W_DYNAMIC_ARRAY_GROW(name)                                               \
    do {                                                                         \
        W_DYNAMIC_ARRAY_ALLOC_SIZE(name) = W_DYNAMIC_ARRAY_ALLOC_SIZE(name) ?    \
            (W_DYNAMIC_ARRAY_ALLOC_SIZE(name) << 1) : 8;                         \
        name = W_REALLOC(W_DYNAMIC_ARRAY_HEADER(name),                           \
            sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE) +                                \
            W_DYNAMIC_ARRAY_ALLOC_SIZE(name) * W_DYNAMIC_ARRAY_ELEM_SIZE(name)); \
        if ((name) == NULL)                                                      \
            W_ERROR_ALLOCATION;                                                  \
        name = W_REF_VOID_PTR(name,sizeof(W_DYNAMIC_ARRAY_HEADER_TYPE));                \
    } while (0)

#endif
