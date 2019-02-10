## Character and String Handling
    
### W_PP_CHARSEQ_TO_STRING(seq,buf,size)
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
buf                  A char buffer
size                 The size of the buffer
```
    Use W_PP_CHARSEQ_TO_STRING to convert a sequence of characters to a string.
    
### W_PP_CHARSEQ_TO_UINT(T,seq)
```C
T                    An unsigned integer type name, e.g. unsigned or uint64_t
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
    Use W_PP_CHARSEQ_TO_UINT to convert a sequence of characters to an unsigned integer.
    
### W_PP_CHARSEQ_TOLOWER(seq)
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
    Use W_PP_CHARSEQ_TOLOWER to convert a sequence of characters to lower case.
    
### W_PP_CHARSEQ_TOUPPER(seq)
```C
seq                  A character sequence, e.g. (R)(E)(A)(D)
```
    Use W_PP_CHARSEQ_TOUPPER to convert a sequence of characters to upper case.
    
### W_PP_CHARSEQ_EQUAL(seq1,seq2)
```C
seq1                 A character sequence, e.g. (R)(E)(A)(D)
seq2                 A character sequence, e.g. (R)(E)(A)(D)
```
    Use W_PP_CHARSEQ_EQUAL to test if two sequences of characters are equal.
    
### W_PP_CHAR_TO_CHAR(ch)
```C
ch                   A character to be converted to ASCII.
```
    Use W_PP_CHAR_TO_CHAR to convert a single character to a C character.
    'char str[] = { 'a', 'b', 0 };'
    
### W_PP_CHAR_TO_INT(ch)
```C
ch                   A character to be converted to integer.
```
    Use W_PP_CHAR_TO_INT to convert a single character to an integer.
