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

### Array macros

#### W_ARRAY_FOR_EACH(T,elem,array[,size])
    Iterates all elements of an array.

#### W_ARRAY_FOR_EACH_REVERSED(T,elem,array[,size])
    Iterates all elements of an array in reversed order.

#### W_ARRAY_GET_SIZE(a)
    Returns the allocation size of a statically allocated array.

#### W_ARRAY_MOVE_LEFT(a,size,pos,offset)
    Move elements left in an array.

#### W_ARRAY_MOVE_RIGHT(a,size,pos,offset)
    Move elements right in an array.

### Debugging

#### W_LOG(...)
    Write a log message.

### Dynamic Array

#### W_DYNAMIC_ARRAY_INIT(name,T,init_size)
    Initializes a dynamic array.

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

#### W_DYNAMIC_ARRAY_REMOVE(array,pos[,nbr_of_elems])
    Remove elements from a dynamic array.

#### W_DYNAMIC_ARRAY_FREE(array)
    Destroys a dynamic array.


### Dynamic Stack


#### W_DYNAMIC_STACK_INIT(stack,T,init_size)
    Initializes a dynamic stack.

#### W_DYNAMIC_STACK_PEEK(stack)
    Gets the toppest element in a dynamic stack.

#### W_DYNAMIC_STACK_POP(stack)
    Gets and removes the toppest element in a dynamic stack.

#### W_DYNAMIC_STACK_PUSH(stack,...)
    Pushes elements to a dynamic stack.

#### W_DYNAMIC_STACK_FREE(stack)
    Destroys a dynamic stack.


### Pre-Processor Programming

#### W_CAT(...)
    Concatenates given arguments. Similar to BOOST_PP_CAT except that takes up to 16 arguments.

#### W_ID(id)
    Provides a more hygienic id name.

#### W_LABEL(id1,id2)
    Constructs line-unique labels.

#### W_STRINGIZE(...)
    Stringizes its arguments. Similar to BOOST_PP_STRINGIZE except that takes up to 16 arguments.


### Mathematics

#### W_ABS(a)
    Returns the absolute value of a.

#### W_SIGN(a)
    Returns the sign of a.

#### W_MAX(...)
    Returns maximum of given arguments (up to four).

#### W_MIN(...)
    Returns minimum of given arguments (up to four).


### Sorting

#### W_NUMERIC_CMP_ASC(a,b)
    Returns -1 if a<b, 0 if a=b and 1 if a>b.

#### W_NUMERIC_CMP_DESC(a,b)
    Returns -1 if a>b, 0 if a=b and 1 if a<b.

#### W_SWAP(T,a,b)
    Swaps a and b of type T.

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


### Compiler Tools

#### W_CONTAINER_OF(ptr,T,member)
    Gets the pointer to the beginning of a given struct based on a pointer to a member of the struct.

#### W_HIDDEN_CONTAINER_OF(ptr,T)
    Gets the pointer to the hidden container of a pointer of type T.

#### W_HIDDEN_OF(ptr,T,member)
    Access a member of a hidden container of type T.

#### W_REF_VOID_PTR(ptr,offset)
    A pointer is referenced using an offset in bytes.

#### W_UNUSED(id)
    Kills a compiler warning caused by an unused variable.


### Strings and Characters

#### W_TO_CHAR(ch)
    Converts a single character identifier to a C string, i.g. a to 'a'.

