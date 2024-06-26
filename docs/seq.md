## Pre-processor Sequence Utilities
    
### W_SEQ_FOR_EACH_COMBINATION(seq, n, macro)
#### Arguments
```C
seq                  a sequence from which combinations are taken (maximum length is eight elements)
n                    number of elements to be picked from the sequence
macro                a macro to be expanded for each selected element set (the macro should take n arguments)
```
#### Description
    Use W_SEQ_FOR_EACH_COMBINATION to expand a given macro for each combination in a sequence.
    The combinations are expanded in lexicographical order.  For example,
    W_SEQ_FOR_EACH_COMBINATION((en)(de)(fr)(es)(it)(pl)(cs)(pt), 2, TEST_TRANSLATE)
    expands TEST_TRANSLATE taking two arguments for each possible combination of the given
    eight langauge identifiers.
    
### W_SEQ_FOR_EACH_PERMUTATION(seq,macro)
#### Arguments
```C
seq                  a sequence from which the permutations are taken (maximum length is six elements)
macro                a macro to be expanded for each permutation (the macro should take the same number of arguments than in the sequenece)
```
#### Description
    Use W_SEQ_FOR_EACH_PERMUTATION to expand a given macro for each permutation
    of a sequence. The permutations are expanded in gray coded order. For example,
    W_SEQ_FOR_EACH_PERMUTATION((a)(b)(c), TEST) expands to TEST(a,b,c) TEST(b,a,c)
    TEST(c,a,b) TEST(a,c,b) TEST(b,c,a) TEST(c,b,a).
    
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
    Use W_SEQ_MEDIAN to get the median of a Boost pre-processor sequence at pre-processing time.
    The result is a sequence having one or two values depending on the length of the given sequence.
    For even length, the result sequence has two values, the first one being always less or equal to
    the second value. For example, W_SEQ_MEDIAN((5)(3)(0)(7)) expands to (3)(5). In order to change
    the comparison macro, redefine W_SEQ_SORT_COMPARE before applying the macro.
    
### W_SEQ_MIN(...)
#### Arguments
```C
seq                  a Boost pre-processor sequence of integer values (up to six values) between 0...255
```
#### Description
    Use W_SEQ_MIN to get the maximum  value in a given sequence at pre-processing time.
    For example, W_SEQ_MIN((5)(2)(0)) expands to 0.
    
### W_SEQ_SORT(seq)
#### Arguments
```C
seq                  a Boost pre-processor sequence to be sorted (maximum sequence length is eight).
```
#### Description
    Use W_SEQ_SORT to sort a Boost pre-processor sequence at pre-processing time.
    For example, W_SEQ_SORT((5)(3)(0)(7)) expands to (0)(3)(5)(7). In order to change
    the comparison macro, redefine W_SEQ_SORT_COMPARE before applying the macro.
    
### W_SEQ_SWAP(seq,a,b)
#### Arguments
```C
seq                  a Boost pre-processor sequence, e.g. (1)(2)(3)
a                    an index in the sequence
b                    an index in the sequence
```
#### Description
    Use W_SEQ_SWAP to swap two positions in a Boost pre-processor sequence.
