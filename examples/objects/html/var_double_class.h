#define CLASS var_double

#define var_double__define                    \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(var_double,to_string)            \
                                              \
    VAR(read,char*,name)                      \
    VAR(read,char*,format)                    \
    /**/
