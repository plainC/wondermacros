# Wondermacros - Generally useful macros for C/C++ programming.

## Intro

Writting a C/C++ macro library is hard. There exists just few of them,
typically with a very narrow focus. Our focus is generally useful
programming techniques which is too wide topic to be specific. Thus,
Wondermacros is just a bag of macros of various kinds. We try to be
C99 compliant, though some macros may require [C11 struct initialization](https://en.cppreference.com/w/c/language/struct_initialization),
for example. The code is free under BSD/MIT style license, see each
file separately.

We try not to reinvent the wheel and build on top of [Boost pre-processor
library](https://www.boost.org/doc/libs/1_67_0/libs/preprocessor/doc/index.html).
It can be used in C programming as well, it is not just for
C++, since it does not bring in any code other than pre-processor macros.
So in order to use macros which use Boost macros you need to have Boost
library installed during build time. But this dependency is just a build
time dependency.

We will also incorporate some great macros of others. For instance, some
macros build on Simon Tatham's [metaprogramming macros](https://www.chiark.greenend.org.uk/~sgtatham/mp/)
which provide a general purpose toolkit for building looping macros and other useful
control structures. The original mp.h is included in Wondermacros.

Best Regards,
J.P. Iivonen <wondermacros@yahoo.com>


## Installation

The package contains just header files. To install wondermacros directory
under /usr/include, type 'make install' as root.


## Macro Reference


### The package contains the following macros:

#### W_ARRAY_FOR_EACH(T,elem,array[,size])
    Iterates all elements in an array.

#### W_ARRAY_GET_SIZE(a)
    Returns the allocation size of a statically allocated array.

#### W_CAT(...)
    Concatenates given arguments. Similar to BOOST_PP_CAT except that takes up to 16 arguments.

#### W_CONTAINER_OF(ptr,T,member)
    Gets the pointer to the beginning of a given struct based on a pointer to a member of the struct.

#### W_DYNAMIC_ARRAY_INIT(name,T,init_size)
    Initializes a dynamic array.

#### W_DYNAMIC_ARRAY_ELEM_SIZE(array)
    Gets the element size of a dynamic array.

#### W_DYNAMIC_ARRAY_ALLOC_SIZE(array)
    Gets the current allocation size of a dynamic array.

#### W_DYNAMIC_ARRAY_SIZE(array)
    Gets the number of elements in a dynamic array.

#### W_DYNAMIC_ARRAY_STEAL_LAST(array)
    Gets and removes the last element in a dynamic array.

#### W_DYNAMIC_ARRAY_PEEK_LAST(array)
    Gets the last element in a dynamic array.

#### W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(array,value)
    Gets the last element in a dynamic array, or returns given value if empty.

#### W_DYNAMIC_ARRAY_PUSH(array,...)
    Adds elements to a dynamic array.

#### W_DYNAMIC_ARRAY_CLEAR(array)
    Removes all elements of a dynamic array but keeps the header. No need to reinitialize.

#### W_DYNAMIC_ARRAY_FREE(array)
    Destroys a dynamic array.

#### W_DYNAMIC_STACK_INIT(stack,T,init_size)
    Initializes a dynamic stack.

#### W_DYNAMIC_STACK_PEEK(stack)
    Gets the toppest element in a dynamic stack.

#### W_DYNAMIC_STACK_POP(stack)
    Gets and removes the toppest element in a dynamic stack.

#### W_DYNAMIC_STACK_PUSH(stack,...)
    Pushes elements to a dynamic stack.

#### W_DYNAMIC_STACK_CLEAR(stack)
    Removes all elements of a dynamic stack but keeps the header. No need to reinitialize.

#### W_DYNAMIC_STACK_FREE(stack)
    Destroys a dynamic stack.

#### W_ID(id)
    Provides a more hygienic id name.

#### W_MAX(...)
    Returns maximum of given arguments (up to four).

#### W_MIN(...)
    Returns minimum of given arguments (up to four).

#### W_NUMERIC_CMP_ASC(a,b)
    Returns -1 if a<b, 0 if a=b and 1 if a>b.

#### W_NUMERIC_CMP_DESC(a,b)
    Returns -1 if a>b, 0 if a=b and 1 if a<b.

#### W_REF_VOID_PTR(ptr,offset)
    A pointer is referenced using an offset in bytes.

#### W_STRINGIZE(...)
    Stringizes its arguments. Similar to BOOST_PP_STRINGIZE except that takes up to 16 arguments.

#### W_SWAP(T,a,b)
    Swaps a and b of type T.

#### W_TO_CHAR(ch)
    Converts a single character identifier to a C string, i.g. a to 'a'.

#### W_UNUSED(id)
    Kills a compiler warning caused by an unused variable.

#### W_VARIADIC_IS_EQUAL(...)
    Compares if given arguments are equal.

#### W_VARIADIC_IS_IN_ASC_ORDER(...)
    Compares if given arguments are in ascending order.

#### W_VARIADIC_IS_IN_DESC_ORDER(...)
    Compares if given arguments are in descending order.

#### W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...)
    Compares if given arguments are in total ascending order.

#### W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...)
    Compares if given arguments are in total descending order.
