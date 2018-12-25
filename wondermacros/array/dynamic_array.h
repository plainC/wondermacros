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


/***
 *** Name:        W_DYNAMIC_ARRAY_DECLARE
 *** Proto:       W_DYNAMIC_ARRAY_DECLARE(T,name)
 ***
 *** Arg:         T      type name   Type name of array elements
 *** Arg:         name   array name  Array name to be declared
 ***
 *** Description: Use W_DYNAMIC_ARRAY to declare a dynamic array.
 *** Example:     W_DYNAMIC_ARRAY_DECLARE(int, array); W_DYNAMIC_ARRAY_INIT(array, int, 8);
 ***/
#define W_DYNAMIC_ARRAY_DECLARE(T,name)                                       \
    struct {                                                                  \
        T* elem;                                                              \
        int alloc_size;                                                       \
        int nbr_of_elems;                                                     \
        int elem_size;                                                        \
    } name
    /* End of W_DYNAMIC_ARRAY_DECLARE */

/***
 *** Name:        W_DYNAMIC_ARRAY_ELEM
 *** Proto:       W_DYNAMIC_ARRAY_ELEM(name,index)
 ***
 *** Arg:         name   array name  Array name
 *** Arg:         index  index nbr   Index of the element
 ***
 *** Description: Use W_DYNAMIC_ARRAY_ELEM to get an element value of an array.
 ***/
#define W_DYNAMIC_ARRAY_ELEM(name, index) ((name).elem[index])

/***
 *** Name:        W_DYNAMIC_ARRAY_SIZE
 *** Proto:       W_DYNAMIC_ARRAY_SIZE(name)
 ***
 *** Arg:         name   array name  Array name
 ***
 *** Description: Use W_DYNAMIC_ARRAY_SIZE to get the number of elements in the array.
 ***/
#define W_DYNAMIC_ARRAY_SIZE(name) ((name).nbr_of_elems)

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
#define W_DYNAMIC_ARRAY_INIT(name,elem_type,init_size)                        \
    do {                                                                      \
        (name).alloc_size = (init_size);                                      \
        (name).elem_size = sizeof(elem_type);                                 \
        (name).nbr_of_elems = 0;                                              \
        (name).elem = W_MALLOC((init_size) * sizeof(elem_type));              \
        if ((name).elem == NULL)                                              \
            W_ERROR_ALLOCATION;                                               \
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
        W_FREE((name).elem);                                                  \
        (name).elem = NULL;                                                   \
        (name).alloc_size = 0;                                                \
        (name).nbr_of_elems = 0;                                              \
    } while (0)

#define W_DYNAMIC_ARRAY_FREE(name)                                            \
    do {                                                                      \
        W_FREE((name).elem);                                                  \
        W_FREE(name);                                                         \
    } while (0)


#define _W_DYNAMIC_ARRAY_PUSH(r,name,i,e)                                     \
    (name).elem[(name).nbr_of_elems + i] = e;

/***
 *** Name:        W_DYNAMIC_ARRAY_PUSH
 *** Proto:       W_DYNAMIC_ARRAY_PUSH(name,...)
 ***
 *** Arg:         name      array name  Array name
 *** Arg:         ...       values      Values to be pushed into a dynamic array
 ***
 *** Description: Use W_DYNAMIC_ARRAY_PUSH to add values to a dynamic array.
 ***/
#define W_DYNAMIC_ARRAY_PUSH(name,...)                                        \
    do {                                                                      \
        while ((name).alloc_size - (name).nbr_of_elems <                      \
            BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))                              \
            W_DYNAMIC_ARRAY_GROW(name);                                       \
        BOOST_PP_SEQ_FOR_EACH_I(_W_DYNAMIC_ARRAY_PUSH,name,                   \
            BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))                            \
        (name).nbr_of_elems += BOOST_PP_VARIADIC_SIZE(__VA_ARGS__);           \
    } while (0)

#define W_DYNAMIC_ARRAY_GROW(name)                                            \
    do {                                                                      \
        (name).alloc_size = (name).alloc_size ? ((name).alloc_size << 1) : 8; \
        (name).elem = W_REALLOC((name).elem,                                  \
            (name).alloc_size * (name).elem_size);                            \
        if ((name).elem == NULL)                                              \
            W_ERROR_ALLOCATION;                                               \
    } while (0)

#endif
