## Character and String Handling
    
### W_CHARSEQ_TO_STRING(seq,buf,size)
    Use W_CHARSEQ_TO_STRING to convert a sequence of characters to a string.
    
### W_CHARSEQ_TO_UINT(T,seq)
    Use W_CHARSEQ_TO_UINT to convert a sequence of characters to an unsigned integer.
    
### W_CHARSEQ_TOLOWER(seq)
    Use W_CHARSEQ_TOLOWER to convert a sequence of characters to lower case.
    
### W_CHARSEQ_TOUPPER(seq)
    Use W_CHARSEQ_TOUPPER to convert a sequence of characters to upper case.
    
### W_FOR_STRING_AS_UINT(T,u,str)
    Use W_FOR_STRING_AS_UINT to convert a string to an unsigned integer.
    If the string is longer than the unsigned type can handle it is truncated.
    
### W_TO_CHAR(ch)
    Use W_TO_CHAR to convert a single character to a C character.
    'char str[] = { 'a', 'b', 0 };'
