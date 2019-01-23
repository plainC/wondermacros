#define CLASS Point

#include "Ipoint.h"

#define Point__methods \
    M_MOVE_UP(Point)   \
    M_MOVE_LEFT(Point) \
    M_DRAW(Point)      \
    /**/

#define Point__vars \
    VAR(read,int,x) \
    VAR(read,int,y) \
    /**/
