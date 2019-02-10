## Generic Array Macros
    
### W_ARRAY_GET_SIZE(a)
    
```C
a                    A static array
    
```
    Use W_ARRAY_GET_SIZE to obtain the allocation size of a static array.
    
### W_ARRAY_FOR_EACH(T,elem,array[,size])
    
```C
T                    a type name of array elements
elem                 a free identifier name
array                a pointer to an array
size                 number of elements in the array (if omitted static size obtained using sizeof is used)
    
```
    Use W_ARRAY_FOR_EACH to iterate all elements of an array.
    Note:        The index of the element is stored in 'elem ## _ix'.
    W_ARRAY_FOR_EACH(int, a, array) {
    printf("%d: %d\n", a_ix, a);
    }
    
### W_ARRAY_FOR_EACH_REVERSED(T,elem,array[,size])
    
```C
T                    type name of array elements
elem                 a free identifier name
array                a pointer to an array
size                 number of elements in the array (if omitted static size obtained using sizeof is used)
    
```
    Use W_ARRAY_FOR_EACH_REVERSED to iterate all elements of an array in reversed order.
    Note:        The index of the element is stored in 'elem ## _ix'.
    W_ARRAY_FOR_EACH(int, a, array) {
    printf("%d: %d\n", a_ix, a);
    }
    
### W_ARRAY_MOVE_LEFT(array,size,pos,offset)
```C
array                a pointer to an array
size                 size of the array
pos                  start position (index) in the array
offset               steps to be moved
```
    Use W_ARRAY_MOVE_LEFT to move items in an array to left by given offset.
    
### W_ARRAY_MOVE_RIGHT(array,size,pos,offset)
```C
array                a pointer to an array
size                 size of the array
pos                  start position (index) in the array
offset               steps to be moved
```
    Use W_ARRAY_MOVE_RIGHT to move items in an array to right by given offset.
