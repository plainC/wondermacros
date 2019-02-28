#define CLASS dom_list

#define dom_list__define                      \
    /* Inherits */                            \
    html__define                              \
                                              \
    METHOD(dom_list,public,int,append_child,  \
        (struct html* child))                 \
    OVERRIDE(dom_list,to_string)              \
                                              \
    VAR(read,struct html**,docs)              \
    /**/
