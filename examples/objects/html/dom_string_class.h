#define CLASS dom_string

#define dom_string__define                    \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(dom_string,to_string)            \
                                              \
    VAR(read,char*,value)                     \
    /**/
