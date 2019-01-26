#define CLASS css_elem

#define css_elem__define                      \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(css_elem,to_string)              \
                                              \
    VAR(read,struct css_selector*,selector)   \
    VAR(read,char*,declarations)             \
    /**/
