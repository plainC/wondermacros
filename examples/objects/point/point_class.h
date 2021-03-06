#define CLASS Point

#define NO_DESTRUCT
#define BUILD_JSON

#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,private,void,ping,(const char* message))     \
    METHOD(Point,public,void,draw)                            \
                       \
    VAR(read,int,r,Array(2) JSON(json_int_array_2))    \
    VAR(read,int,x,JSON(json_int))    \
    VAR(read,int,y,JSON(json_int))    \
    VAR(read,struct Owner*,a,JSON(json_object))    \
    /**/
