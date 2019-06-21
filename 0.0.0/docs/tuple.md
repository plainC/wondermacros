## Tuples
    
### W_TUPLE_TYPE(type_seq)
#### Arguments
```C
type_seq             a sequence of types (e.g. `(int)(double)(const char*)`
```
#### Description
    Use W_TUPLE_TYPE to get an anonymous struct for a tuple.
    
### W_TUPLE_INIT(type_seq,ptr,...)
#### Arguments
```C
type_seq             a sequence of types (e.g. `(int)(double)(const char*)`
ptr                  a pointer for writting (sizeof(W_TUPLE_TYPE(type_seq))
...                  values of the tuple
```
#### Description
    Use W_TUPLE_INIT to initialize a tuple.
    
### W_TUPLE_NEW(type_seq,...)
#### Arguments
```C
type_seq             a sequence of types (e.g. `(int)(double)(const char*)`
...                  values of the tuple
```
#### Description
    Use W_TUPLE_NEW to allocate and initialize a tuple.
    
### W_TUPLE_ELEM(tuplep,ix)
#### Arguments
```C
tuplep               a pointer to a tuple
ix                   an index of an element in the tuple
```
#### Description
    Use W_TUPLE_ELEM to access (read or assign) an individual element in the tuple.
