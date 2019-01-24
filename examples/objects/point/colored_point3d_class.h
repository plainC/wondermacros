#define CLASS ColoredPoint3D

#include "Ipoint.h"

#define ColoredPoint3D__methods   \
    ColoredPoint__methods         \
    OVERLOAD(ColoredPoint3D,draw) \
    /**/

#define ColoredPoint3D__vars      \
    ColoredPoint__vars            \
    VAR(read,int,z)               \
    /**/
