#define CLASS array

#define array__define                         \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(array,to_string)                 \
                                              \
    VAR(read,char*,name)                      \
    VAR(read,struct html*,child)              \
    /**/
