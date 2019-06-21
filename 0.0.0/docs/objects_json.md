### JSON Serialization and Marshalling

Objects can be automatically serialized to JSON strings and marshalled from JSON as well. To build JSON support
for a class add `#define BUILD_JSON` to the class file. Each property which is chosen to be including in JSON
serialization and marshaling must be marked as such using the fourth argument position in `VAR` macro. The
prefix of the C function which does the conversion must be given there inside `JSON(<function prefix>)` macro.
For example, `VAR(public,int,x,JSON(json_int))` works for `int` type. Use `JSON(json_string)` for `const char*`
and so on.

The JSON conversion callbacks must be linked into the exceutable. Many of these exists under 
[objects/json directory](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/) (e.g.
JSON conversion for [int](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/int.c).

| C Type      | 4th argument to VAR    | As JSON         |
| ----------- | ---------------------- | --------------- |
| Any object  | JSON(json_object)      | { ... }         |
| bool        | JSON(json_bool)        | true or false   |
| int         | JSON(json_boolean)     | true or false   |
| int         | JSON(json_int)         | ]-2^31, 2^31[   |
| int64_t     | JSON(json_int64)       | ]-2^63, 2^63[   |
| unsigned    | JSON(json_unsigned)    | [0, 2^32[       |
| uint64_t    | JSON(json_unsigned64)  | [0, 2^64[       |
| char        | JSON(json_char)        | [0,255]         |
| string      | JSON(json_string)      | "..."           |
| float       | JSON(json_float)       | 32 bit float    |
| double      | JSON(json_double)      | 64 bit float    |
| long double | JSON(json_long_double) | 80 bit float    |

If none of the types in the previous table does not apply, JSON conversion must be implemented.
This is the case for array types, for example. There exists sample code for
[int[2] array](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/int_array_2.c).
That can be used for a property `VAR(public,foo,int,Array(2) JSON(int_array_2))`, for instance.
To implement JSON conversion for a type two functions must be provided. They are:

* `int json_<type name>_to_string(void* value, char* buffer, size_t size)`
* `int json_<type name>_from_string(const char* buffer, const char** endptr, void* value)`

`to_string` returns the number of characters written to buffer, or -1 on error. The `value` argument points
to the storage location of the property.

`from_string` returns 0 if the conversion is successful, 1 otherwise. The `value` argument points to the
storage location of the property. `endptr` should point to the first character that was not used.


