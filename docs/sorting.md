## Sorting
    
### W_NUMERIC_CMP_ASC(a,b)
#### Arguments
```C
a                    A value to be compared
b                    A value to be compared
```
#### Description
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
#### Return Value
-1, if a < b, 0 if a == b, and 1 if a > b.
#### Notes
Both a and b are evaluated twice.
    
### W_NUMERIC_CMP_DESC(a,b)
#### Arguments
```C
a                    A value to be compared
b                    A value to be compared
```
#### Description
    Use W_NUMERIC_CMP_ASC to compare two values of the same numeric types.
#### Return Value
-1, if a > b, 0 if a == b, and 1 if a < b.
#### Notes
Both a and b are evaluated twice.
    
### W_SWAP(T,a,b)
#### Arguments
```C
T                    type name       The type of both a and b.
a                    a value A value to be swapped
b                    a value A value to be swapped
```
#### Description
    Use W_SWAP to swap the values of a and b. Neither of them can be constants.
#### Notes
Both a and b are evaluated twice.
    
### W_VARIADIC_SORT(T,...)
#### Arguments
```C
T                    type name
...                  variables to be sorted in-place
```
#### Description
    Use W_VARIADIC_SORT to sort variables (or array references etc.) in-place.
    This is probably the fastest method to get the job done.
    Redefine COMPARE to alter comparison method.
#### Return Value
This is a statement macro.
#### Notes
The maximum number of arguments depends on the number of sorting networks supplied.
    Redefine SORTING_NETWORK_TYPE to supply a different set of sorting networks.
    Given arguments are evaluated multiple times.
    Given arguments have to be writtable as well, sorting is done in-place.
    
#### Example
```C
int a=5, b=2, c=0, d=9, e=3;
```
    W_VARIADIC_SORT(int, a,b,c,d,e);
    
    now a=0, b=2, c=3, d=5 and e=9.
    
### W_VARIADIC_IS_EQUAL(...)
#### Arguments
```C
...                  elements to be tested
```
#### Description
    Use W_VARIADIC_IS_EQUAL to test if given values are all equal.
    Expands to an expression like (a == b && b == c && ...).
#### Return Value
1 if elements are equal, 0 otherwise.
#### Notes
All inputs are evaluated multiple times.
    Redefine W_COMPARE in order to change the comparison method.
#### Example
```C
W_VARIADIC_IS_EQUAL(1,2,3,4) evaluates to 0.
```
    
### W_VARIADIC_IS_IN_ASC_ORDER(...)
#### Arguments
```C
...                  elements to be tested
```
#### Description
    Use W_VARIADIC_IS_IN_ASC_ORDER to test if given input is in ascending order.
#### Return Value
1 if elements are in ascending order, 0 otherwise.
#### Notes
All inputs are evaluated multiple times.
    Redefine W_COMPARE in order to change the comparison method.
#### Example
```C
W_VARIADIC_IS_IN_ASC_ORDER(1,2,3,4) evaluates to 1.
```
    
### W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(...)
#### Arguments
```C
...                  elements to be tested
```
#### Description
    Use W_VARIADIC_IS_IN_TOTAL_ASC_ORDER to test if given input is in total ascending order.
#### Return Value
1 if elements are in ascending order, 0 otherwise.
#### Notes
All inputs are evaluated multiple times.
    Redefine W_COMPARE in order to change the comparison method.
#### Example
```C
W_VARIADIC_IS_IN_TOTAL_ASC_ORDER(1,2,3,4) evaluates to 1.
```
    
### W_VARIADIC_IS_IN_DESC_ORDER(...)
#### Arguments
```C
...                  elements to be tested
```
#### Description
    Use W_VARIADIC_IS_IN_DESC_ORDER to test if given input is in descending order.
#### Return Value
1 if elements are in descending order, 0 otherwise.
#### Notes
All inputs are evaluated multiple times.
    Redefine W_COMPARE in order to change the comparison method.
#### Example
```C
W_VARIADIC_IS_IN_DESC_ORDER(3,3,2,1) evaluates to 1.
```
    
### W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(...)
#### Arguments
```C
...                  elements to be tested
```
#### Description
    Use W_VARIADIC_IS_IN_TOTAL_DESC_ORDER to test if given input is in total descending order.
#### Return Value
1 if elements are in total descending order, 0 otherwise.
#### Notes
All inputs are evaluated multiple times.
    Redefine W_COMPARE in order to change the comparison method.
#### Example
```C
W_VARIADIC_IS_IN_TOTAL_DESC_ORDER(4,3,2,1) evaluates to 1.
```
    
### W_SEQ_TO_COMPARE_EXPR(seq,method,comp_op,comp_value,log_op,neutral_value)
#### Arguments
```C
seq                  a sequence of values to be compared
method               a function or macro name used in comparisons
comp_op              comparison operator
comp_value           comparison value
log_op               logical operator
neutral_value        neutral value
```
#### Description
    Use W_SEQ_TO_COMPARE_EXPR to test equality or order multiple values, for example.
#### Return Value
1 or 0.
#### Notes
All inputs are evaluated multiple times.
#### Example
```C
W_SEQ_TO_COMPARE((1)(2)(3)(4), W_NUMERIC_CMP_ASC, <=, 0, &&, 1) compares ascending order and evaluates to 1.
```
#### Example
```C
W_SEQ_TO_COMPARE((1)(2)(3)(4), W_NUMERIC_CMP_ASC, ==, 0, &&, 1) compares equality and evaluates to 0.
```
