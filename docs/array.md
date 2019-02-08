## Generic Array Macros
    
### W_ARRAY_GET_SIZE(a)
    
    
    Use W_ARRAY_GET_SIZE to obtain the allocation size of a static array.
    
### W_ARRAY_FOR_EACH(T,elem,array[,size])
    
    omitted static size obtained using sizeof is used)
    
    Use W_ARRAY_FOR_EACH to iterate all elements of an array.
    Note:        The index of the element is stored in 'elem ## _ix'.
    W_ARRAY_FOR_EACH(int, a, array) {
    printf("%d: %d\n", a_ix, a);
    }
    
### W_ARRAY_FOR_EACH_REVERSED(T,elem,array[,size])
    
    omitted static size obtained using sizeof is used)
    
    Use W_ARRAY_FOR_EACH_REVERSED to iterate all elements of an array in reversed order.
    Note:        The index of the element is stored in 'elem ## _ix'.
    W_ARRAY_FOR_EACH(int, a, array) {
    printf("%d: %d\n", a_ix, a);
    }
    
### W_ARRAY_MOVE_LEFT(array,size,pos,offset)
    Use W_ARRAY_MOVE_LEFT to move items in an array to left by given offset.
