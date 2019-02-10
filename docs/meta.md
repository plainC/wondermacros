## Meta-programming
    
### W_BEFORE(labelid,before)
#### Arguments
```C
labelid              A unique label identifier, e.g. foo if foo is not used already
before               The code to be run before the following statement.
```
#### Description
    Use W_BEFORE to run the code given in the argument 'before' and then
    the suffixed statement.
    'before' should have the syntactic form of one or more declarations
    and statements, except that a trailing semicolon may be omitted.
    Any declarations will be in scope only within 'before', not within
    the suffixed statement.
    This macro, unusually among the collection, is naturally
    transparent to 'break' and also transparent to 'continue'.
    
### W_CAT(...)
#### Arguments
```C
...                  identifiers to be concatenated
```
#### Description
    Use W_CAT to concatenate its arguments after they have been expanded.
    
### W_CAT_INNER(...)
#### Arguments
```C
...                  identifiers to be concatenated
```
#### Description
    Use W_CAT_INNER to concatenate its arguments after they have been expanded during W_CAT expansion.
    This macro is identical to W_CAT but sometimes we need to concatenate another time during W_CAT
    expansion.
    
### W_CAT_OUTER(...)
#### Arguments
```C
...                  identifiers to be concatenated
```
#### Description
    Use W_CAT_OUTER to concatenate its arguments after they have been expanded during W_CAT expansion.
    This macro is identical to W_CAT but sometimes we need to concatenate another time during W_CAT
    expansion.
    
### W_DECLARE(labelid, declaration)
#### Arguments
```C
labelid              An unique label identifier
declaration          The declaration
```
#### Description
    Use W_DECLARE to run the 'declaration' argument before the suffixed
    statement. The argument may have the form of either a C expression
    (e.g. an assignment) or a declaration; if the latter, it will be in
    scope within the suffixed statement.
    This macro is break-unsafe - it causes a 'break' to terminate the
    suffixed statement only. If you need different behaviour, you can
    use W_BREAK_CATCH and W_BREAK_THROW to pass a break past it.
    
### W_ID(id)
#### Arguments
```C
id                   identifier name
```
#### Description
    Use W_ID to provide a more hygienic identifier name to be used in a macro.
#### Return Value
Expands to an identifier name.
#### Notes
Uses the line number and a prefix to avoid name conflicts. Since a macro
    always expands to a single row all expansions will get the same line number.
    
### W_LABEL(id1,id2)
    
#### Arguments
```C
id1                  label one
id2                  label one
    
```
#### Description
    Use W_LABEL to construct line-unique labels.
    
### W_PP_POW2(i)
#### Arguments
```C
i                    the exponent
```
#### Description
    Use W_PP_POW2 to get power of two for the given exponent.
    The expansion is done at pre-processing time. Redefine W_PP_POW2_TYPE
    to modify the numeric literal type.  The default is unsigned (U).
    
### W_STRINGIZE(...)
#### Arguments
```C
...                  arguments to be converted to text
```
#### Description
    Use W_STRINGIZE to stringize arguments to text.
    
### W_WRAP(id,...)
#### Arguments
```C
id                   The name of the macro being wrapped.
...                  The code of the macro.
```
#### Description
    Use W_WRAP to construct a macro having multiple statements.
    Typically such macros are written inside a 'do...while (0)' block.
    W_WRAP does that and adds the name of the macro to the code (id) in
    order to help the debugging phase.
    
### W_PP_MAX(a,b)
#### Arguments
```C
a                    a constant integer between 0...255
b                    a constant integer between 0...255
```
#### Description
    Use W_PP_MAX to get the maximum of two values at pre-processing time.
    
### W_PP_MIN(a,b)
#### Arguments
```C
a                    a constant integer between 0...255
b                    a constant integer between 0...255
```
#### Description
    Use W_PP_MIN to get the minimum of two values at pre-processing time.
    
### W_PP_POW(a,b)
#### Arguments
```C
a                    a number between 0...255
b                    an exponent between 0...31
```
#### Description
    Use W_PP_POW to get the power a to b. The exponent must be two or, result must be in range [0,255].
