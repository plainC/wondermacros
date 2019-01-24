#ifndef __Ipoint__H
#define __Ipoint__H

#define M_PING(C)                               \
    METHOD(C,private,void,ping,(const char* message))

#define M_MOVE_UP(C)                            \
    METHOD(C,public,int,move_up,(int steps))

#define M_MOVE_LEFT(C)                          \
    METHOD(C,public,int,move_left,(int steps))

#define M_DRAW(C)                               \
    METHOD(C,public,void,draw)

#endif
