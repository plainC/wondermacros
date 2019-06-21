## String Handling
    
### W_FOR_STRING_AS_UINT(T,u,str)
#### Arguments
```C
T                    an unsigned integer type name
u                    a free variable name to be assigned
str                  a string
```
#### Description
    Use W_FOR_STRING_AS_UINT to convert a string to an unsigned integer.
#### Notes
The string must be null terminated.
    If the string is longer than the unsigned type can handle it is truncated.
#### Example
```C
'W_FOR_STRING_AS_UINT(uint64_t,x,buffer) printf("%llu", x);'
```
