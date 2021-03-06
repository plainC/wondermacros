## Singly-Linked Circular List
    
### W_CSLIST_FOR_EACH(T,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_CSLIST_FOR_EACH to traverse all elements in a circular list.
#### Notes
Redefine W_CSLIST_FIELD_NAME to reset the link name (defaults to 'next').
    
### W_CSLIST_FOR_EACH_NAMED(T,next,node,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
node                 a free identifier name
list                 a list to be traversed
```
#### Description
    Use W_CSLIST_FOR_EACH_NAMED to traverse all elements in a circular list.
    
### W_CSLIST_PREPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_CSLIST_PREPEND to prepend a circular list to another circular list.
    
### W_CSLIST_PREPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_CSLIST_PREPEND_NAMED to prepend a circular list to another circular list.
    
### W_CSLIST_APPEND(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_CSLIST_APPEND to append a circular list to another circular list.
    
### W_CSLIST_APPEND_NAMED(T,self,list)
#### Arguments
```C
T                    a type name (the type of the list nodes)
next                 a member field name of the next link
self                 a list to be modified
list                 a list to be prepended
```
#### Description
    Use W_CSLIST_APPEND_NAMED to append a circular list to another circular list.
