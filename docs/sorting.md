## Sorting
    
### W_NUMERIC_CMP_ASC(a,b)
```C
a                    A value to be compared
b                    A value to be compared
```
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_NUMERIC_CMP_DESC(a,b)
```C
a                    A value to be compared
b                    A value to be compared
```
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
    
### W_SWAP(T,a,b)
```C
T                    type name       The type of both a and b.
a                    a value A value to be swapped
b                    a value A value to be swapped
```
    Use W_SWAP to swap the values of a and b. Neither of them can be constants.
    
### W_VARIADIC_SORT(T,...)
```C
T                    type name
...                  variables to be sorted in-place
```
    Use W_VARIADIC_SORT to sort variables (or array references etc.) in-place.
    This is probably the fastest method to get the job done.
    Redefine COMPARE to alter comparison method.
    Redefine SORTING_NETWORK_TYPE to supply a different set of sorting networks.
    Given arguments are evaluated multiple times.
    Given arguments have to be writtable as well, sorting is done in-place.
    
    W_VARIADIC_SORT(int, a,b,c,d,e);
    
    now a=0, b=2, c=3, d=5 and e=9.
    
### W_VARIADIC_IS_EQUAL(...)
```C
...                  elements to be tested
```
    Use W_VARIADIC_IS_EQUAL to test if given values are all equal.
    Expands to an expression like (a == b && b == c && ...).
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_ASC_ORDER(...)
```C
...                  elements to be tested
```
    Use W_VARIADIC_IS_IN_ASC_ORDER to test if given input is in ascending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...)
```C
...                  elements to be tested
```
    Use W_VARIADIC_IS_IN_TOTAL_ASC_ORDER to test if given input is in total ascending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_DESC_ORDER(...)
```C
...                  elements to be tested
```
    Use W_VARIADIC_IS_IN_DESC_ORDER to test if given input is in descending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...)
```C
...                  elements to be tested
```
    Use W_VARIADIC_IS_IN_TOTAL_DESC_ORDER to test if given input is in total descending order.
    Redefine W_COMPARE in order to change the comparison method.
    
### W_SEQ_TO_COMPARE_EXPR(seq,method,comp_op,comp_value,log_op,neutral_value)
```C
seq                  a sequence of values to be compared
method               a function or macro name used in comparisons
comp_op              comparison operator
comp_value           comparison value
log_op               logical operator
neutral_value        neutral value
```
    Use W_SEQ_TO_COMPARE_EXPR to test equality or order multiple values, for example.
