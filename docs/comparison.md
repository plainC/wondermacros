## Comparison
    
### W_BYTE_COMPARE(buf,...)
#### Arguments
```C
buf                  a buffer (or a string) to match
...                  variadic number of bytes (or characters)
```
#### Description
    Use W_BYTE_COMPARE to test if a given buffer contains given bytes. If the buffer is not \0-terminated, it must be large enough for testing.
    
### W_IS_ANY_OF(value,...)
#### Arguments
```C
value                a value to be tested
...                  variadic number of values
```
#### Description
    Use W_IS_ANY_OF to test if a given value is equal to any of the given other values.
