#define CLASS ColoredPoint3D

#define ColoredPoint3D__define    \
    /* Inherits */                \
    ColoredPoint__define          \
    INHERIT(ColoredPoint)         \
                                  \
    OVERLOAD(ColoredPoint3D,draw) \
                                  \
    VAR(read,int,z)               \
    /**/
