#define CLASS model

#define model__define                                                    \
    /* Inherits */                                                       \
      /*none */                                                          \
                                                                         \
    METHOD(model,public,int,bind_ptr,                                    \
        (const char* name, int type, void* ptr))                         \
    METHOD(model,public,void*,get,                                       \
        (const char* name))                                              \
                                                                         \
    VAR(private,struct variable**,variables)                             \
                                                                         \
    /**/
