#define CLASS ptr_double

#define ptr_double__define                    \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(ptr_double,to_string)            \
                                              \
    VAR(public,double*,value)                 \
    /**/
