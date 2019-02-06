#define CLASS html

#define html__define                                                     \
    /* Inherits */                                                       \
      /*none */                                                          \
                                                                         \
    METHOD(html,public,int,to_string,                                    \
        (struct model* model, struct view_context* context))             \
                                                                         \
    /**/
