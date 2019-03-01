#define CLASS Owner

#define NO_CONSTRUCT
#define NO_DESTRUCT
#define BUILD_JSON

#define Owner__define                    \
    /* Inherits */                       \
      /*none */                          \
                                         \
                                         \
    VAR(read,int,id,JSON(json_int))      \
    VAR(read,int,number,JSON(json_int))  \
    /**/
