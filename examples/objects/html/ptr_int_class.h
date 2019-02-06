#define CLASS ptr_int

#define ptr_int__define                       \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(ptr_int,to_string)               \
                                              \
    VAR(public,int*,value)                    \
    /**/
