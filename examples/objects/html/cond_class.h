#define CLASS cond

#define cond__define                          \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERRIDE(cond,to_string)                  \
                                              \
    VAR(read,char*,name)                      \
    VAR(public,struct html*,child)            \
    /**/
