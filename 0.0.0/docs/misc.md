## Misc
    
### W_STRUCT_INIT(T,ptr,...)
#### Arguments
```C
T                    a type name
ptr                  a pointer to newly allocated memory of size T at minimum
...                  initial values for the structure (e.g. '.x=1, .y=2' or just '1,2')
```
#### Description
    Use W_STRUCT_INIT to initialize a newly allocated structure.
    
### W_STRUCT_NEW(T,ptr,...)
#### Arguments
```C
T                    a type name
...                  initial values for the structure (e.g. '.x=1, .y=2' or just '1,2')
```
#### Description
    Use W_STRUCT_NEW to allocate and initialize a structure.
    
### W_UNUSED(id)
#### Arguments
```C
id                   a name of unused identifier.
```
#### Description
    Use W_UNUSED to kill a warning if an identifier is unused.
