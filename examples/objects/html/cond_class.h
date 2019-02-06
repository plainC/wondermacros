#define CLASS cond

#define cond__define                          \
    /* Inherits */                            \
    html__define                              \
                                              \
    OVERLOAD(cond,to_string)                  \
                                              \
    VAR(read,char*,name)                      \
    VAR(public,struct html*,child)            \
    /**/
