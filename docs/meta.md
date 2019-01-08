## Meta-programming
    
### W_ID(id)
    Use W_ID to provide a more hygienic identifier name to be used in a macro.
    always expands to a single row all expansions will get the same line number.
    
### W_LABEL(id1,id2)
    
    
    Use W_LABEL to construct line-unique labels.
    
### W_WRAP(id,...)
    Use W_WRAP to construct a macro having multiple statements.
    Typically such macros are written inside a 'do...while (0)' block.
    W_WRAP does that and adds the name of the macro to the code (id) in
    order to help the debugging phase.
