#define CLASS js_elem

#define js_elem__define                       \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(js_elem,to_string)               \
                                              \
    VAR(read,struct html*,script)             \
    /**/
