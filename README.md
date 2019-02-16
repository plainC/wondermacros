# Wondermacros - A Programming Platform for the Best and Bravest C Programmers

## Intro

Wondermacros aims to bring in features of modern programming languages to C
through macros.  C macros in general are not recommended for a reason.  Most
of the issues can be avoided by writting macros using strict guidelines but
the biggest issue remains; programs having macros may be hard to debug and
maintain. Thus, Wondermacros are just for the best and bravest C programmers.

Wondermacros is for C11 standard at the moment. Most of the macros are fully
functional with C99 as well.

Wondermacros aims to provide full programming platform toolkit including
* Object-Oriented Programming Toolkit
* Generic Data Structures
  * Deque
  * Dynamic array
  * Dynamic stack
  * Hash table
  * Singly-linked list
  * Doubly-linked list
  * Singly-linked circular list
* Various X-macros to expand code from compact specifications in consistent
manner
* Iterative generic tree traversal macros: for_each_preorder and for_each_postorder
* Generic array manipulation: get_size (for statically allocated arrays), for_each, for_each_reversed, move_left, and move_right
* Pointer macros
* Sorting macros
* Metaprogramming macros for writting macros: loop building macros and various others
* Pre-processor mathematic macros
* Pre-processor string (character sequence) macros

This project is still a work in progress, so stay tuned. The following major
enhancements are planned:
* Dynamic arrays and other data structures using W_HIDDEN macros underneath does not yet support propert alignment
* AVL tree, and heap

We try not to reinvent the wheel and build on top of [Boost pre-processor
library](https://www.boost.org/doc/libs/1_67_0/libs/preprocessor/doc/index.html).

We will also incorporate some great macros of others. For instance, some
macros build on Simon Tatham's [metaprogramming macros](https://www.chiark.greenend.org.uk/~sgtatham/mp/)
which provide a general purpose toolkit for building looping macros and other useful
control structures.

Best Regards,
J.P. Iivonen <wondermacros@yahoo.com>

## Projects using Wondermacros:
* [Web Elements](https://github.com/plainC/web_elements)


## Installation

The package contains just header files. To install wondermacros directory
under /usr/include, type 'make install' as root.

## Examples

See some examples under examples directory. To build them, first install
Wondermacros using 'make install' as root.  Then type 'make'. This will also
build the regression test suite (see the next chapter).


## Regression Test Set

To run regression tests, go to under main level directory test and type make
to compile. The regression tests are written directly to the macro files.
To run all tests type ./test/wondermacros after building the test set.


## Macro Reference

## X-Macros
### [Object-Oriented Programming](https://github.com/plainC/wondermacros/blob/master/docs/objects.md)
### [Generic Enum, String Array, Picked Value Array, and Switch...Case Block Generation](https://github.com/plainC/wondermacros/blob/master/docs/generic_x.md)
### [Unit Testing](https://github.com/plainC/wondermacros/blob/master/docs/test.md)
## Data Structures
### [Deque](https://github.com/plainC/wondermacros/blob/master/docs/deque.md)
### [Dynamic Array](https://github.com/plainC/wondermacros/blob/master/docs/dynamic_array.md)
### [Dynamic Stack](https://github.com/plainC/wondermacros/blob/master/docs/dynamic_stack.md)
### [Hash Table](https://github.com/plainC/wondermacros/blob/master/docs/hash_table.md)
### [Singly-Linked List](https://github.com/plainC/wondermacros/blob/master/docs/slist.md)
### [Doubly-Linked List](https://github.com/plainC/wondermacros/blob/master/docs/dlist.md)
### [Singly-Linked Circular List](https://github.com/plainC/wondermacros/blob/master/docs/cslist.md)
### [Trees](https://github.com/plainC/wondermacros/blob/master/docs/tree.md)

## Others
### [Object-Oriented API](https://github.com/plainC/wondermacros/blob/master/docs/object_api.md)
### [Generic Array Macros](https://github.com/plainC/wondermacros/blob/master/docs/array.md)
### [Pointer Macros](https://github.com/plainC/wondermacros/blob/master/docs/pointer.md)
### [Debugging](https://github.com/plainC/wondermacros/blob/master/docs/debug.md)
### [Macro Programming Helppers](https://github.com/plainC/wondermacros/blob/master/docs/meta.md)
### [Pre-Processor Character and String Tools](https://github.com/plainC/wondermacros/blob/master/docs/pp_char.md)
### [Pre-Processor Mathematic Tools](https://github.com/plainC/wondermacros/blob/master/docs/pp_math.md)
### [Mathematics](https://github.com/plainC/wondermacros/blob/master/docs/math.md)
### [Sorting](https://github.com/plainC/wondermacros/blob/master/docs/sorting.md)
### [String Handling](https://github.com/plainC/wondermacros/blob/master/docs/string.md)
### [Misc](https://github.com/plainC/wondermacros/blob/master/docs/misc.md)
