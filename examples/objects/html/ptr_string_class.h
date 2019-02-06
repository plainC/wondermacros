#define CLASS ptr_string

#define ptr_string__define                    \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(ptr_string,to_string)            \
                                              \
    VAR(public,char**,value)                  \
    /**/
