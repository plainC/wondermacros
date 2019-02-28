#define CLASS css_selector

#define css_selector__define                  \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(css_selector,to_string)          \
                                              \
    VAR(read,char*,elem)                      \
    /**/
