#define CLASS Point

#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,private,void,ping,(const char* message))     \
    METHOD(Point,public,void,draw)                            \
                       \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
