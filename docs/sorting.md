## Sorting
    
### W_BUBBLESORT(T,collection)
    Use W_BUBBLESORT to sort a collection with a random access API.
    The sorting is done in-place.
    Uses W_GET(collection,i) to read from collection using index i.
    Uses W_SET(collection,i,val) to write to collection.
    Redefine these macros to sort any collection.
    
### W_HEAPSORT(T,collection)
    Use W_HEAPSORT to sort a collection with a random access API.
    The sorting is done in-place.
    Uses GET(collection,i) to read from collection using index i.
    Uses SET(collection,i,val) to write to collection.
    Uses GET_SIZE(collection,size) to read the collection size to size.
    Redefine these macros to sort any collection.
    
### W_NUMERIC_CMP_ASC(a,b)
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_NUMERIC_CMP_DESC(a,b)
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_SWAP(T,a,b)
    Use W_SWAP to swap the values of a and b. Neither of them can be constants.
    
### W_VARIADIC_SORT(T,...)
    Use W_VARIADIC_SORT to sort variables (or array references etc.) in-place.
    This is probably the fastest method to get the job done.
    Redefine COMPARE to alter comparison method.
    Redefine SORTING_NETWORK_TYPE to supply a different set of sorting networks.
    Given arguments are evaluated multiple times.
    Given arguments have to be writtable as well, sorting is done in-place.
    
    W_VARIADIC_SORT(int, a,b,c,d,e);
    
    now a=0, b=2, c=3, d=5 and e=9.
    
### W_VARIADIC_IS_EQUAL(...)
    Use W_VARIADIC_IS_EQUAL to test if given values are all equal.
    Expands to an expression like (a == b && b == c && ...).
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_ASC_ORDER(...)
    Use W_VARIADIC_IS_IN_ASC_ORDER to test if given input is in ascending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...)
    Use W_VARIADIC_IS_IN_TOTAL_ASC_ORDER to test if given input is in total ascending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_DESC_ORDER(...)
    Use W_VARIADIC_IS_IN_DESC_ORDER to test if given input is in descending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...)
    Use W_VARIADIC_IS_IN_TOTAL_DESC_ORDER to test if given input is in total descending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_SEQ_TO_COMPARE_EXPR(seq,method,comp_op,comp_value,log_op,neutral_value)
    Use W_SEQ_TO_COMPARE_EXPR to test equality or order multiple values, for example.
