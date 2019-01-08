## Sorting
    
### W_NUMERIC_CMP_ASC(a,b)
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_NUMERIC_CMP_DESC(a,b)
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_SWAP(T,a,b)
    Use W_SWAP to swap the values of a and b. Neither of them can be constants.
    
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
