#define CLASS Point

#include "Ipoint.h"

#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    M_MOVE_UP(Point)   \
    M_MOVE_LEFT(Point) \
    M_PING(Point)      \
    M_DRAW(Point)      \
                       \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
