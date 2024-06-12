## Pre-Processor Mathematics
    
### W_PP_DECOMPOSE(n)
#### Arguments
```C
n                    an integer between 0...255
```
#### Description
    Use W_PP_DECOMPOSE to get the decomposition of n at pre-processing time. The representation of the decomposition is a boost sequence. For example, W_PP_DECOMPOSE(156) expands to ((13)(1)) ((3)(1)) ((2)(2)), which means 13^1 * 3^1 * 2^2.
    
### W_PP_EVEN(a)
#### Arguments
```C
a                    a constant integer between 0...255
```
#### Description
    Use W_PP_EVEN to check whether a constant value is even at pre-processing time.
    
### W_PP_IS_PRIME(n)
#### Arguments
```C
n                    an integer between 0...255
```
#### Description
    Use W_PP_IS_PRIME to test if given argument is a prime number during pre-processing.
    
### W_PP_MAX(...)
#### Arguments
```C
...                  a variadic number of integer arguments (up to eight arguments) between 0...255
```
#### Description
    Use W_PP_MAX to get the maximum  value of given arguments at pre-processing time.
    
### W_PP_MEDIAN(...)
#### Arguments
```C
...                  variadic number of integer arguments (up to eight arguments) between 0...255
```
#### Description
    Use W_PP_MEDIAN to get the median of values of arguments at pre-processing time. The result is a boost sequence. If the given arguments contain even number of arguments, the result sequence has two values, the first one being less or equal to the second. For instance, W_PP_MEDIAN(5,2,7) returns (5) and W_PP_MEDIAN(7,2,4,5) returns (4)(5).
    
### W_PP_MIN(...)
#### Arguments
```C
...                  variadic number of integer arguments (up to eight arguments) between 0...255
```
#### Description
    Use W_PP_MIN to get the minimum of value of arguments at pre-processing time.
    
### W_PP_ODD(a)
#### Arguments
```C
a                    a constant integer between 0...255
```
#### Description
    Use W_PP_ODD to check whether a constant value is odd at pre-processing time.
    
### W_PP_POW(a,b)
#### Arguments
```C
a                    a number between 0...255
b                    an exponent between 0...31
```
#### Description
    Use W_PP_POW to get the power a to b. The exponent must be two or, result must be in range [0,255].
