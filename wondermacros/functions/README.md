# Function helpers

This directory contains some functions to help writing macros.
In order to write an expression macro which returns a value,
one often would need to use GCC specific extensions. This can
be often avoided by using a helper function. The macro just
provides type independent interface for the function.

## w_list_length

Returns the length of the list.

```
static inline int cc_list_length(void* list, size_t offset)
```
