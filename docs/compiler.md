## Compiler Tools
    
### W_HIDDEN_CONTAINER_OF(ptr,T)
#### Arguments
```C
ptr                  a pointer to a structure having a hidden header.
T                    type of the hidden header.
```
#### Description
    Use W_HIDDEN_CONTAINER_OF to get a pointer to the actual container of on object having a hidden header.
    
### W_HIDDEN_OF(ptr,T,member)
#### Arguments
```C
ptr                  a pointer to a structure having a hidden header.
T                    type of the hidden header.
member               member field name of the header.
```
#### Description
    Use W_HIDDEN_OF to get a value of a field in the hidden header of a structure.
    
### W_REF_VOID_PTR(ptr,offset)
#### Arguments
```C
ptr                  a pointer       A pointer to be referenced by an offset.
offset               an offset       An offset in bytes.
```
#### Description
    Use W_REF_VOID_PTR to reference a void pointer using an offset in bytes.
    
### W_UNUSED(id)
#### Arguments
```C
id                   identifier name       The name of unused identifier.
```
#### Description
    Use W_UNUSED to kill a warning if an identifier is unused.
