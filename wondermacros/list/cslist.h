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

#ifndef __W_CSLIST_H
#define __W_CSLIST_H

#include <wondermacros/meta/id.h>


#ifndef W_CSLIST_FIELD_NEXT
# define W_CSLIST_FIELD_NEXT next
#endif

/***
 *** Name:        W_CSLIST_FOR_EACH
 *** Proto:       W_CSLIST_FOR_EACH(T,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_CSLIST_FOR_EACH to traverse all elements in a circular list.
 *** Notes:       Redefine W_CSLIST_FIELD_NAME to reset the link name (defaults to 'next').
 ***/
#define W_CSLIST_FOR_EACH(T,node,list)            \
    W_CSLIST_FOR_EACH_NAMED(T,W_CSLIST_FIELD_NEXT,node,list)

/***
 *** Name:        W_CSLIST_FOR_EACH_NAMED
 *** Proto:       W_CSLIST_FOR_EACH_NAMED(T,next,node,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         node       a free identifier name
 *** Arg:         list       a list to be traversed
 *** Description: Use W_CSLIST_FOR_EACH_NAMED to traverse all elements in a circular list.
 ***/
#define W_CSLIST_FOR_EACH_NAMED(T,next,node,list) \
    for (T* W_ID(l) = (list); W_ID(l); W_ID(l) = NULL) \
        for (T* node = W_ID(l)->next, *W_ID(n);             \
            node && (W_ID(n) = node->next, 1); \
            node = W_ID(n) != W_ID(l)->next ? W_ID(n) : NULL)


/***
 *** Name:        W_CSLIST_PREPEND
 *** Proto:       W_CSLIST_PREPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_CSLIST_PREPEND to prepend a circular list to another circular list.
 ***/
#define W_CSLIST_PREPEND(T,self,list)             \
    W_CSLIST_PREPEND_NAMED(T,W_CSLIST_FIELD_NEXT,self,list)

/***
 *** Name:        W_CSLIST_PREPEND_NAMED
 *** Proto:       W_CSLIST_PREPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_CSLIST_PREPEND_NAMED to prepend a circular list to another circular list.
 ***/
#define W_CSLIST_PREPEND_NAMED(T,next,self,list)   \
    do {                                           \
        if (self) {                                \
            T* W_ID(t) = self->next;               \
            self->next = list->next;               \
            list->next = W_ID(t);                  \
        } else                                     \
            self = list->next;                     \
    } while (0)



/***
 *** Name:        W_CSLIST_APPEND
 *** Proto:       W_CSLIST_APPEND(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_CSLIST_APPEND to append a circular list to another circular list.
 ***/
#define W_CSLIST_APPEND(T,self,list)              \
    W_CSLIST_APPEND_NAMED(T,W_CSLIST_FIELD_NEXT,self,list)

/***
 *** Name:        W_CSLIST_APPEND_NAMED
 *** Proto:       W_CSLIST_APPEND_NAMED(T,self,list)
 *** Arg:         T          a type name (the type of the list nodes)
 *** Arg:         next       a member field name of the next link
 *** Arg:         self       a list to be modified
 *** Arg:         list       a list to be prepended
 *** Description: Use W_CSLIST_APPEND_NAMED to append a circular list to another circular list.
 ***/
#define W_CSLIST_APPEND_NAMED(T,next,self,list)  \
    do {                                         \
        if (!(self))                             \
            self = list;                         \
        else {                                   \
            T* W_ID(t) = (self)->next;           \
            (self)->next = (list);               \
            (list)->next = W_ID(t);              \
            (self) = (list);                     \
        }                                        \
    } while (0)


#endif

