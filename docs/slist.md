## Singly-Linked List
    
### W_SLIST_FOR_EACH(T,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_SLIST_FOR_EACH to traverse all elements in a list.
#### Notes
Redefine W_SLIST_FIELD_NAME to reset the link name (defaults to 'next').
    
### W_SLIST_FOR_EACH_NAMED(T,next,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_SLIST_FOR_EACH_NAMED to traverse all elements in a list.
    
### W_SLIST_PREPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_SLIST_PREPEND to prepend a list to another list.
    
### W_SLIST_PREPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_SLIST_PREPEND_NAMED to prepend a list to another list.
    
### W_SLIST_APPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_SLIST_APPEND to append a list to another list.
    
### W_SLIST_APPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_SLIST_APPEND_NAMED to append a list to another list.
