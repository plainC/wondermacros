#define CLASS ColoredPoint3D

#include "Ipoint.h"

#define ColoredPoint3D__methods   \
    /* inherits */                \
    ColoredPoint__methods         \
                                  \
    OVERLOAD(ColoredPoint3D,draw) \
    /**/

#define ColoredPoint3D__vars      \
    /* inherits */                \
    ColoredPoint__vars            \
                                  \
    VAR(read,int,z)               \
    /**/
