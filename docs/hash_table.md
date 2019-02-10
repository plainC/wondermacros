## Hash Table
    
### W_HASH_TABLE_INIT(H,pow2_size)
#### Arguments
```C
H                    a pointer to a hash table.
pow2_size            size of the hash table (an exponent of power two)
```
#### Description
    Use W_HASH_TABLE_FREE to free a hash table.
    
### W_HASH_TABLE_PUSH(T,H,Key,Value)
#### Arguments
```C
T                    type name of a hash mapping
H                    a pointer to a hash table.
Key                  a key to be mapped
Value                a value to be mapped
```
#### Description
    Use W_HASH_TABLE_FREE to free a hash table.
    
### W_HASH_TABLE_FOR_EACH_MATCH(T,match,H,Key)
#### Arguments
```C
T                    type name of a hash mapping
match                a free variable
H                    a pointer to a hash table.
Key                  key to be matched
```
#### Description
    Use W_HASH_TABLE_FREE to free a hash table.
    
### W_HASH_TABLE_FREE(H)
#### Arguments
```C
H                    a pointer to a hash table.
```
#### Description
    Use W_HASH_TABLE_FREE to free a hash table.
    
### W_HASH_TABLE_REMOVE(H,Key,matched)
#### Arguments
```C
H                    a pointer to a hash table.
Key                  key to be removed
matched              integer variable to be set if a mapping is removed
```
#### Description
    Use W_HASH_TABLE_FREE to free a hash table.
