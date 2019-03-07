#define CLASS Point

#define NO_DESTRUCT

#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,private,void,ping,(const char* message))     \
    METHOD(Point,public,void,draw)                            \
    SIGNAL(on_move, int steps)                                     \
                       \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
