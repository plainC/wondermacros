#define CLASS html_attr

#define html_attr__define                     \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(html_attr,to_string)             \
                                              \
    VAR(read,enum html_attr_tag,tag)          \
    VAR(read,char*,value)                     \
    /**/
