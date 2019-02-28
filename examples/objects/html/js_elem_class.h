#define CLASS js_elem

#define js_elem__define                       \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(js_elem,to_string)               \
                                              \
    VAR(read,struct html*,script)             \
    /**/
