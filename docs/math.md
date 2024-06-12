## Mathematics
    
### W_ABS(a)
#### Arguments
```C
a                    a value
```
#### Description
    Use W_ABS to get the absolute value.
#### Notes
Redefine W_GE, W_ZERO and W_NEG to change the default operators.
    
### W_FOR_CEILING_POW2(T,pow2,a)
#### Arguments
```C
T                    an unsigned type name (e.g. `unsigned` or `uint64_t`)
pow2                 a free variable name to be assigned
a                    a value
```
#### Description
    Use W_FOR_CEILING_POW2 to round up to next power of two.
    
### W_MAX(...)
#### Arguments
```C
...                  values to be compared (from one up to four)
```
#### Description
    Use W_MAX to get the maximum of given values.
    
### W_MIN(...)
#### Arguments
```C
...                  values to be compared (from one up to four)
```
#### Description
    Use W_MIN to get the minimum of given values.
#### Notes
Redefine W_LE, W_ZERO and W_COMPARE to change the default operators.
    
### W_SIGN(x)
#### Arguments
```C
x                    a numeric value
```
#### Description
    Use W_SIGN to get the sign of a number, i.g. -1 for negative, 0 for zero, and 1 for positive numbers.
    
### W_UINT_AVERAGE_FLOOR(x, y)
#### Arguments
```C
x                    an unsigned numeric value
y                    an unsigned numeric value
```
#### Description
    Use W_UINT_AVERAGE_FLOOR to get the average (floor) of two unsigned integers without overflow or division operator.
    
### W_UINT_AVERAGE_CEIL(x, y)
#### Arguments
```C
x                    an unsigned numeric value
y                    an unsigned numeric value
```
#### Description
    Use W_UINT_AVERAGE_CEIL to get the average (ceil) of two unsigned integers without overflow or division operator.
