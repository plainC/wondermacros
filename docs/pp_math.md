## Pre-Processor Mathematics
    
### W_PP_DECOMPOSE(n)
#### Arguments
```C
n                    an integer between 0...255
```
#### Description
    Use W_PP_DECOMPOSE to get the decomposition of n at pre-processing time. The representation of the decomposition is a boost sequence. For example, W_PP_DECOMPOSE(156) expands to ((13)(1)) ((3)(1)) ((2)(2)), which means 13^1 * 3^1 * 2^2.
    
### W_PP_IS_PRIME(n)
#### Arguments
```C
n                    an integer between 0...255
```
#### Description
    Use W_PP_IS_PRIME to test if given argument is a prime number during pre-processing.
    
### W_PP_MAX(a,b)
#### Arguments
```C
a                    a constant integer between 0...255
b                    a constant integer between 0...255
```
#### Description
    Use W_PP_MAX to get the maximum of two values at pre-processing time.
    
### W_PP_MIN(a,b)
#### Arguments
```C
a                    a constant integer between 0...255
b                    a constant integer between 0...255
```
#### Description
    Use W_PP_MIN to get the minimum of two values at pre-processing time.
    
### W_PP_POW(a,b)
#### Arguments
```C
a                    a number between 0...255
b                    an exponent between 0...31
```
#### Description
    Use W_PP_POW to get the power a to b. The exponent must be two or, result must be in range [0,255].
