#define CLASS ColoredPoint

#include "Ipoint.h"

#define ColoredPoint__methods   \
    /* inherits */              \
    Point__methods              \
                                \
    OVERLOAD(ColoredPoint,draw) \
    /**/

#define ColoredPoint__vars      \
    /* inherits */              \
    Point__vars                 \
                                \
    VAR(read,const char*,color) \
    /**/
