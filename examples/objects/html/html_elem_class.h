#define CLASS html_elem

#define html_elem__define                     \
    /* Inherits */                            \
    html__define                              \
                                              \
    METHOD(html_elem,public,int,append_child, \
        (struct html* child))                 \
    OVERRIDE(html_elem,to_string)             \
                                              \
    VAR(read,enum html_elem_tag,tag)          \
    VAR(read,struct html_attr**,attrs)              \
    VAR(read,struct html**,next)              \
    /**/
