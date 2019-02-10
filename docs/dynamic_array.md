## Dynamic Array
    
### W_DYNAMIC_ARRAY_SIZE(array)
    
```C
array                A pointer to a dynamic array
    
```
    Use W_DYNAMIC_ARRAY_SIZE to get the number of elements in the array.
    
### W_DYNAMIC_ARRAY_ALLOC_SIZE(array)
    
```C
array                A pointer to an array
    
```
    Use W_DYNAMIC_ARRAY_ALLOC_SIZE to get the current allocation size.
    
### W_DYNAMIC_ARRAY_STEAL_LAST(array)
    
```C
array                array  A pointer to a dynamic array
    
```
    Use W_DYNAMIC_ARRAY_STEAL_LAST to get and remove the last element in the array.
    
### W_DYNAMIC_ARRAY_PEEK_LAST(array)
    
```C
array                array  A pointer to a dynamic array
    
```
    Use W_DYNAMIC_ARRAY_PEEK_LAST to get the last element in the array.
    
### W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(array,value)
    
```C
array                array    A pointer to a dynamic array
value                a value  A value returned if the array is empty
    
```
    Use W_DYNAMIC_ARRAY_PEEK_LAST_SAFE to get the last element in the array.
    If the array is empty, the given value is returned.
    
### W_DYNAMIC_ARRAY_INIT(name,T,init_size)
    
```C
array                Array pointer
init_size            Initial allocation size for the array
    
```
    Use W_DYNAMIC_ARRAY_INIT to initialize a dynamic array.
    
### W_DYNAMIC_ARRAY_FREE(array)
    
```C
array                a dynamic array
    
```
    Use W_DYNAMIC_ARRAY_FREE to free a dynamic array.
    
### W_DYNAMIC_ARRAY_PUSH(array,...)
    
```C
array                Array pointer
...                  Values to be pushed into a dynamic array
    
```
    Use W_DYNAMIC_ARRAY_PUSH to add values to a dynamic array.
    
### W_DYNAMIC_ARRAY_REMOVE(array,pos[,nbr_of_elems])
    
```C
array                Array pointer
pos                  Array index
nbr_of_elems         Number of elements to be removed (default is one).
    
```
    Use W_DYNAMIC_ARRAY_REMOVE to remove elements from a dynamic array.
