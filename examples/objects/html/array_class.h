#define CLASS array

#define array__define                         \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(array,to_string)                 \
                                              \
    VAR(read,char*,name)                      \
    VAR(read,struct html*,child)              \
    /**/
