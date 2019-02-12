/* (C) is Copyright 2019 J.P. Iivonen <wondermacros@yahoo.com>
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

#ifndef __W_DLIST_H
#define __W_DLIST_H

#include <wondermacros/meta/id.h>


#ifndef W_DLIST_FIELD_NEXT
# define W_DLIST_FIELD_NEXT next
#endif

#ifndef W_DLIST_FIELD_PREV
# define W_DLIST_FIELD_PREV prev
#endif

/***
 *** Name:        W_DLIST_FOR_EACH
 *** Proto:       W_DLIST_FOR_EACH(T,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_DLIST_FOR_EACH to traverse all elements in a doubly-linked list.
 *** Notes:       Redefine W_DLIST_FIELD_NEXT and W_DLIST_FIELD_PREV to reset the link name (defaults to 'next').
 ***/
#define W_DLIST_FOR_EACH(T,node,list)            \
    W_DLIST_FOR_EACH_NAMED(T,W_DLIST_FIELD_PREV,W_DLIST_FIELD_NEXT,node,list)

/***
 *** Name:        W_DLIST_FOR_EACH_NAMED
 *** Proto:       W_DLIST_FOR_EACH_NAMED(T,prev,next,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         prev       a member field name of the previous link
 *** Arg:         next       a member field name of the next link
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_DLIST_FOR_EACH_NAMED to traverse all elements in a doubly-linked list.
 ***/
#define W_DLIST_FOR_EACH_NAMED(T,prev,next,node,list) \
    for (T* node = (list), *W_ID(n);             \
        node && (W_ID(n) = node->next,1);        \
        node = W_ID(n))


/***
 *** Name:        W_DLIST_PREPEND
 *** Proto:       W_DLIST_PREPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_DLIST_PREPEND to prepend a list to another doubly-linked list.
 ***/
#define W_DLIST_PREPEND(T,self,list)             \
    W_DLIST_PREPEND_NAMED(T,W_DLIST_FIELD_PREV,W_DLIST_FIELD_NEXT,self,list)

/***
 *** Name:        W_DLIST_PREPEND_NAMED
 *** Proto:       W_DLIST_PREPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_DLIST_PREPEND_NAMED to prepend a list to another doubly-linked list.
 ***/
#define W_DLIST_PREPEND_NAMED(T,prev,next,self,list)  \
    do {                                         \
        W_DLIST_FOR_EACH(T, W_ID(l), list) {     \
            if (W_ID(l)->next == NULL) {         \
                W_ID(l)->next = self;            \
                if (self)                        \
                    self->prev = W_ID(l);        \
                (self) = list;                   \
                break;                           \
            }                                    \
        }                                        \
    } while (0)



/***
 *** Name:        W_DLIST_APPEND
 *** Proto:       W_DLIST_APPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_DLIST_APPEND to append a list to another doubly-linked list.
 ***/
#define W_DLIST_APPEND(T,self,list)              \
    W_DLIST_APPEND_NAMED(T,W_DLIST_FIELD_PREV,W_DLIST_FIELD_NEXT,self,list)

/***
 *** Name:        W_DLIST_APPEND_NAMED
 *** Proto:       W_DLIST_APPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_DLIST_APPEND_NAMED to append a list to another doubly-linked list.
 ***/
#define W_DLIST_APPEND_NAMED(T,prev,next,self,list)   \
    do {                                         \
        if (self)                                \
            W_DLIST_FOR_EACH(T, W_ID(l), self) { \
                if (W_ID(l)->next == NULL) {     \
                    W_ID(l)->next = list;        \
                    if (list)                    \
                        list->prev = W_ID(l);    \
                    break;                       \
                }                                \
            }                                    \
        else                                     \
            self = list;                         \
    } while (0)


/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#else
# include <wondermacros/misc/struct_init.h>
# include <wondermacros/misc/struct_new.h>
#endif

W_TEST(W_DLIST_APPEND,
    struct int_list {
        int value;
        struct int_list* next;
        struct int_list* prev;
    };

    struct int_list* a = W_STRUCT_NEW(struct int_list, .value=1);
    struct int_list* b = W_STRUCT_NEW(struct int_list, .value=2);
    struct int_list* c = W_STRUCT_NEW(struct int_list, .value=3);

    struct int_list* list = NULL;
    W_DLIST_APPEND(struct int_list, list, a);
    W_DLIST_APPEND(struct int_list, list, b);
    W_DLIST_APPEND(struct int_list, list, c);

    int correct[] = { 1, 2, 3 };
    int ix=0;

    W_DLIST_FOR_EACH(struct int_list, node, list)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");
    W_TEST_ASSERT(ix == 3, "FOR_EACH failed to go through all items");

    W_DLIST_FOR_EACH(struct int_list, node, list)
        free(node);
)

W_TEST(W_DLIST_PREPEND,
    struct int_list {
        int value;
        struct int_list* next;
        struct int_list* prev;
    };

    struct int_list* a = W_STRUCT_NEW(struct int_list, .value=1);
    struct int_list* b = W_STRUCT_NEW(struct int_list, .value=2);
    struct int_list* c = W_STRUCT_NEW(struct int_list, .value=3);

    struct int_list* list = NULL;
    W_DLIST_PREPEND(struct int_list, list, a);
    W_DLIST_PREPEND(struct int_list, list, b);
    W_DLIST_PREPEND(struct int_list, list, c);

    int correct[] = { 3, 2, 1 };
    int ix=0;

    W_DLIST_FOR_EACH(struct int_list, node, list)
        W_TEST_ASSERT(node->value == correct[ix++], "Value mismatch");
    W_TEST_ASSERT(ix == 3, "FOR_EACH failed to go through all items");

    W_DLIST_FOR_EACH(struct int_list, node, list)
        free(node);
)

#endif

