## Compiler Tools
    
### W_HIDDEN_CONTAINER_OF(ptr,T)
```C
ptr                  a pointer to a structure having a hidden header.
T                    type of the hidden header.
```
    Use W_HIDDEN_CONTAINER_OF to get a pointer to the actual container of on object having a hidden header.
    
### W_HIDDEN_OF(ptr,T,member)
```C
ptr                  a pointer to a structure having a hidden header.
T                    type of the hidden header.
member               member field name of the header.
```
    Use W_HIDDEN_OF to get a value of a field in the hidden header of a structure.
    
### W_REF_VOID_PTR(ptr,offset)
```C
ptr                  a pointer       A pointer to be referenced by an offset.
offset               an offset       An offset in bytes.
```
    Use W_REF_VOID_PTR to reference a void pointer using an offset in bytes.
    
### W_UNUSED(id)
```C
id                   identifier name       The name of unused identifier.
```
    Use W_UNUSED to kill a warning if an identifier is unused.
