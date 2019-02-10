## Doubly-Linked List
    
### W_DLIST_FOR_EACH(T,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_DLIST_FOR_EACH to traverse all elements in a doubly-linked list.
#### Notes
Redefine W_DLIST_FIELD_NEXT and W_DLIST_FIELD_PREV to reset the link name (defaults to 'next').
    
### W_DLIST_FOR_EACH_NAMED(T,prev,next,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
prev                 a member field name of the previous link
next                 a member field name of the next link
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_DLIST_FOR_EACH_NAMED to traverse all elements in a doubly-linked list.
    
### W_DLIST_PREPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_DLIST_PREPEND to prepend a list to another doubly-linked list.
    
### W_DLIST_PREPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_DLIST_PREPEND_NAMED to prepend a list to another doubly-linked list.
    
### W_DLIST_APPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_DLIST_APPEND to append a list to another doubly-linked list.
    
### W_DLIST_APPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_DLIST_APPEND_NAMED to append a list to another doubly-linked list.
