#define CLASS ColoredPoint

#include "Ipoint.h"

#define ColoredPoint__methods   \
    Point__methods              \
    OVERLOAD(ColoredPoint,draw) \
    /**/

#define ColoredPoint__vars      \
    Point__vars                 \
    VAR(read,const char*,color) \
    /**/
