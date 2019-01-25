#define CLASS html

#define html__define                                                     \
    /* Inherits */                                                       \
      /*none */                                                          \
                                                                         \
    METHOD(html,public,int,to_string,(char* buffer, size_t size, int* pos)) \
                                                                         \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
