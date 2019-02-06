#define CLASS var_int

#define var_int__define                       \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(var_int,to_string)               \
                                              \
    VAR(read,char*,name)                      \
    /**/
