#define CLASS ColoredPoint3D

#include "Ipoint.h"

#define ColoredPoint3D__define    \
    /* Inherits */                \
    ColoredPoint__define          \
                                  \
    OVERLOAD(ColoredPoint3D,draw) \
                                  \
    VAR(read,int,z)               \
    /**/
