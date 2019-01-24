#define CLASS ColoredPoint

#include "Ipoint.h"

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
                                \
    OVERLOAD(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color) \
    /**/
