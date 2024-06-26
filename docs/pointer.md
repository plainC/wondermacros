## Pointer Macros
    
### W_BYTE_OFFSET(ptr1,ptr2)
#### Arguments
```C
ptr1                 a pointer
ptr2                 a pointer
```
#### Description
    Use W_BYTE_OFFSET to count the offset of two pointers. The offset is negative if ptr1 is before ptr2.
    
### W_FOR_ALIGNED_PTR(T,alignedp,origp,pow2)
#### Arguments
```C
T                    a type name (must be pointer type, e.g. `void*`)
alignedp             a free identifier name for the aligned pointer
origp                a pointer to be aligned
pow2                 alignment (power of 2)
```
#### Description
    Use W_FOR_ALIGNED_PTR to get a properly alinged pointer.
    
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
ptr                  a pointer to be referenced by an offset.
offset               an offset in bytes.
```
#### Description
    Use W_REF_VOID_PTR to reference a void pointer using an offset in bytes.
    
### W_TAGGED_PTR_SET(p, tag)
    
#### Arguments
```C
p                    a pointer
tag                  a tag (length in bits is set by W_TAG_LENGTH)
    
```
#### Description
    Use W_TAGGED_PTR_SET to set a pointer with a tag.
#### Notes
Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
    
### W_TAGGED_PTR_GET_PTR(p)
    
#### Arguments
```C
p                    a pointer
    
```
#### Description
    Use W_TAGGED_PTR_GET_PTR to get the pointer without tag.
#### Notes
Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
    
### W_TAGGED_PTR_GET_TAG(p)
    
#### Arguments
```C
p                    a pointer
    
```
#### Description
    Use W_TAGGED_PTR_GET_TAG to get the tag of tagged pointer.
#### Notes
Redefine W_TAG_LENGTH to set the length of the tag. Default is 3.
    
### W_VALUES_AS_ARRAY(T, ...)
#### Arguments
```C
T                    element type of the array
...                  variadic number of values
```
#### Description
    Use W_VALUES_AS_ARRAY to get a stack reference to given values without declaring temporary variables.
    
### W_VARIADIC_TO_REFS(...)
#### Arguments
```C
...                  arguments to be converted to references
```
#### Description
    Use W_VARIADIC_TO_REFS to convert arguments to references. For instance, you have 'a,b,c,d' but you need '&a,&b,&c,&d'.
