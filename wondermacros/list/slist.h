/* (C) is Copyright 2015 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_SLIST_H
#define __W_SLIST_H

#include <wondermacros/meta/id.h>
#include <wondermacros/functions/list_length.h>


#ifndef W_SLIST_FIELD_NAME
# define W_SLIST_FIELD_NAME next
#endif

/***
 *** Name:        W_SLIST_FOR_EACH
 *** Proto:       W_SLIST_FOR_EACH(T,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_SLIST_FOR_EACH to traverse all elements in a list.
 *** Notes:       Redefine W_SLIST_FIELD_NAME to reset the link name (defaults to 'next').
 ***/
#define W_SLIST_FOR_EACH(T,node,list)            \
    W_SLIST_FOR_EACH_NAMED(T,W_SLIST_FIELD_NAME,node,list)

/***
 *** Name:        W_SLIST_FOR_EACH_NAMED
 *** Proto:       W_SLIST_FOR_EACH_NAMED(T,next,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_SLIST_FOR_EACH_NAMED to traverse all elements in a list.
 ***/
#define W_SLIST_FOR_EACH_NAMED(T,next,node,list) \
    for (T* node = (list), *W_ID(n);             \
        node && (W_ID(n) = node->next,1);        \
        node = W_ID(n))


/***
 *** Name:        W_SLIST_PREPEND
 *** Proto:       W_SLIST_PREPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_SLIST_PREPEND to prepend a list to another list.
 ***/
#define W_SLIST_PREPEND(T,self,list)             \
    W_SLIST_PREPEND_NAMED(T,W_SLIST_FIELD_NAME,self,list)

/***
 *** Name:        W_SLIST_PREPEND_NAMED
 *** Proto:       W_SLIST_PREPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_SLIST_PREPEND_NAMED to prepend a list to another list.
 ***/
#define W_SLIST_PREPEND_NAMED(T,next,self,list)  \
    do {                                         \
        W_SLIST_FOR_EACH(T, W_ID(l), list) {     \
            if (W_ID(l)->next == NULL) {         \
                W_ID(l)->next = self;            \
                (self) = list;                   \
                break;                           \
            }                                    \
        }                                        \
    } while (0)



/***
 *** Name:        W_SLIST_APPEND
 *** Proto:       W_SLIST_APPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_SLIST_APPEND to append a list to another list.
 ***/
#define W_SLIST_APPEND(T,self,list)              \
    W_SLIST_APPEND_NAMED(T,W_SLIST_FIELD_NAME,self,list)

/***
 *** Name:        W_SLIST_APPEND_NAMED
 *** Proto:       W_SLIST_APPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_SLIST_APPEND_NAMED to append a list to another list.
 ***/
#define W_SLIST_APPEND_NAMED(T,next,self,list)   \
    do {                                         \
        if (self)                                \
            W_SLIST_FOR_EACH(T, W_ID(l), self) { \
                if (W_ID(l)->next == NULL) {     \
                    W_ID(l)->next = list;        \
                    break;                       \
                }                                \
            }                                    \
        else                                     \
            self = list;                         \
    } while (0)


/***
 *** Name:        W_SLIST_REVERSE
 *** Proto:       W_SLIST_REVERSE(T,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         list       a list to be reversed
 *** Description: Use W_SLIST_REVERSE to reverse a singly-linked list in-place.
 ***/
#define W_SLIST_REVERSE(T, List)                                \
    do {                                                        \
        T* W_ID(r) = (List);                                    \
        T* W_ID(prev) = NULL;                                   \
        for (T* W_ID(next); W_ID(r); W_ID(r) = W_ID(next)) {    \
            W_ID(next) = W_ID(r)->W_SLIST_FIELD_NAME;           \
            W_ID(r)->W_SLIST_FIELD_NAME = W_ID(prev);           \
            W_ID(prev) = W_ID(r);                               \
        }                                                       \
        (List) = W_ID(prev);                                    \
    } while( 0 )                                                \
    /**/


/***
 *** Name:        W_SLIST_LENGTH
 *** Proto:       W_SLIST_LENGTH(T,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         list       a list
 *** Description: Use W_SLIST_LENGTH to get the length of a singly-linked list.
 ***/
#define W_SLIST_LENGTH(T, List)                                 \
    (w_list_length((List), offsetof(T, W_SLIST_FIELD_NAME)))    \
    /**/


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#else
# include <wondermacros/misc/struct_init.h>
# include <wondermacros/misc/struct_new.h>
#endif

W_TEST(W_SLIST_APPEND,
    struct int_list {
        int value;
        struct int_list* next;
    };

    struct int_list* a = W_STRUCT_NEW(struct int_list, .value=1);
    struct int_list* b = W_STRUCT_NEW(struct int_list, .value=2);
    struct int_list* c = W_STRUCT_NEW(struct int_list, .value=3);

    struct int_list* list = NULL;
    W_SLIST_APPEND(struct int_list, list, a);
    W_SLIST_APPEND(struct int_list, list, b);
    W_SLIST_APPEND(struct int_list, list, c);

    int correct[] = { 1, 2, 3 };
    int ix=0;

    W_SLIST_FOR_EACH(struct int_list, node, list)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");
    W_TEST_ASSERT(ix == 3, "FOR_EACH failed to go through all items");

    W_SLIST_REVERSE(struct int_list, list);
    ix = sizeof(correct) / sizeof(correct[0]) - 1;
    W_SLIST_FOR_EACH(struct int_list, node, list)
        W_TEST_ASSERT(node->value == correct[ix--], "value mismatch");

    W_SLIST_FOR_EACH(struct int_list, node, list)
        free(node);
)

W_TEST(W_SLIST_PREPEND,
    struct int_list {
        int value;
        struct int_list* next;
    };

    struct int_list* a = W_STRUCT_NEW(struct int_list, .value=1);
    struct int_list* b = W_STRUCT_NEW(struct int_list, .value=2);
    struct int_list* c = W_STRUCT_NEW(struct int_list, .value=3);

    struct int_list* list = NULL;
    W_SLIST_PREPEND(struct int_list, list, a);
    W_SLIST_PREPEND(struct int_list, list, b);
    W_SLIST_PREPEND(struct int_list, list, c);

    int correct[] = { 3, 2, 1 };
    int ix=0;

    W_SLIST_FOR_EACH(struct int_list, node, list)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");
    W_TEST_ASSERT(ix == 3, "FOR_EACH failed to go through all items");

    W_TEST_ASSERT(W_SLIST_LENGTH(struct int_list, list) == 3,
                  "value mismatch");

    W_SLIST_FOR_EACH(struct int_list, node, list)
        free(node);
)

#endif
