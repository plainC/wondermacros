#define CLASS dom_string

#define TAGS 1

#define dom_string__define                    \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(dom_string,to_string)            \
                                              \
    VAR(read,char*,value)                     \
    /**/
