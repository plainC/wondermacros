## Character and String Handling
    
### W_PP_CHARSEQ_TO_STRING(seq,buf,size)
#### Arguments
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
buf                  A char buffer
size                 The size of the buffer
```
#### Description
    Use W_PP_CHARSEQ_TO_STRING to convert a sequence of characters to a string.
#### Notes
'size' is evaluated twice.
#### Example
```C
'char buf[16]; W_PP_CHARSEQ_TO_STRING( (A)(B)(C)(D), buf, 16)'
```
    
### W_PP_CHARSEQ_TO_UINT(T,seq)
#### Arguments
```C
T                    An unsigned integer type name, e.g. unsigned or uint64_t
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
#### Description
    Use W_PP_CHARSEQ_TO_UINT to convert a sequence of characters to an unsigned integer.
#### Notes
If the string is longer than the unsigned type can handle it is truncated.
#### Example
```C
'printf("%x", W_PP_CHARSEQ_TO_UINT(unsigned, (A)(B)(C)(D)) );'
```
    
### W_PP_CHARSEQ_TOLOWER(seq)
#### Arguments
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
#### Description
    Use W_PP_CHARSEQ_TOLOWER to convert a sequence of characters to lower case.
#### Example
```C
'W_PP_CHARSEQ_TOLOWER((R)(E)(A)(D))' expands to '(r)(e)(a)(d)'.
```
    
### W_PP_CHARSEQ_TOUPPER(seq)
#### Arguments
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
#### Description
    Use W_PP_CHARSEQ_TOUPPER to convert a sequence of characters to upper case.
#### Example
```C
'W_PP_CHARSEQ_TOUPPER((r)(e)(a)(d))' expands to '(R)(E)(A)(D)'.
```
    
### W_PP_CHARSEQ_EQUAL(seq1,seq2)
#### Arguments
```C
seq1                 A character sequence, e.g. (R)(E)(A)(D)
seq2                 A character sequence, e.g. (R)(E)(A)(D)
```
#### Description
    Use W_PP_CHARSEQ_EQUAL to test if two sequences of characters are equal.
#### Example
```C
'W_PP_CHARSEQ_EQUAL((r)(e)(a)(d), (r)(e)(a)(d))' expands to '1'.
```
    
### W_PP_CHAR_TO_CHAR(ch)
#### Arguments
```C
ch                   A character to be converted to ASCII.
```
#### Description
    Use W_PP_CHAR_TO_CHAR to convert a single character to a C character.
#### Notes
ch must be a valid character to be used in an identifer, i.g. [a-zA-Z_0-9].
#### Example
```C
'char str[] = { W_PP_CHAR_TO_CHAR(a), W_PP_CHAR_TO_CHAR(b), 0 };' expands to
```
    'char str[] = { 'a', 'b', 0 };'
    
### W_PP_CHAR_TO_INT(ch)
#### Arguments
```C
ch                   A character to be converted to integer.
```
#### Description
    Use W_PP_CHAR_TO_INT to convert a single character to an integer.
#### Notes
ch must be a valid character to be used in an identifer, i.g. [a-zA-Z_0-9].
#### Example
```C
'W_PP_CHAR_TO_INT(a)' expands to 65.
```
