#define CLASS tree

#define tree__define                          \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(tree,to_string)                  \
                                              \
    VAR(read,char*,name)                      \
    VAR(read,struct html*,child)              \
    /**/
