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


#endif

