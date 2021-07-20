## Pre-processor Sequence Utilities
    
### W_SEQ_MAX(...)
#### Arguments
```C
seq                  a Boost pre-processor sequence of integer values (up to six values) between 0...255
```
#### Description
    Use W_SEQ_MAX to get the maximum  value in a given sequence at pre-processing time.
    
### W_SEQ_MEDIAN(seq)
#### Arguments
```C
seq                  a Boost pre-processor sequence to be sorted (maximum sequence length is six).
```
#### Description
    Use W_SEQ_MEDIAN to get the median of a Boost pre-processor sequence at pre-processing time. The result is a sequence having one or two values depending on the length of the given sequence. For even length, the result sequence has two values, the first one being always less or equal to the second value. For example, W_SEQ_MEDIAN((5)(3)(0)(7)) expands to (3)(5). In order to change the comparison macro, redefine W_SEQ_SORT_COMPARE before applying the macro.
    
### W_SEQ_MIN(...)
#### Arguments
```C
seq                  a Boost pre-processor sequence of integer values (up to six values) between 0...255
```
#### Description
    Use W_SEQ_MIN to get the maximum  value in a given sequence at pre-processing time. For example, W_SEQ_MIN((5)(2)(0)) expands to 0.
    
### W_SEQ_SORT(seq)
#### Arguments
```C
seq                  a Boost pre-processor sequence to be sorted (maximum sequence length is six).
```
#### Description
    Use W_SEQ_SORT to sort a Boost pre-processor sequence at pre-processing time. For example, W_SEQ_SORT((5)(3)(0)(7)) expands to (0)(3)(5)(7). In order to change the comparison macro, redefine W_SEQ_SORT_COMPARE before applying the macro.
    
### W_SEQ_SWAP(seq,a,b)
#### Arguments
```C
seq                  a Boost pre-processor sequence, e.g. (1)(2)(3)
a                    an index in the sequence
b                    an index in the sequence
```
#### Description
    Use W_SEQ_SWAP to swap two positions in a Boost pre-processor sequence.
