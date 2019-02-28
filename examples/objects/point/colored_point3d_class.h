#define CLASS ColoredPoint3D

#define BUILD_JSON

#define ColoredPoint3D__define    \
    /* Inherits */                \
    ColoredPoint__define          \
    INHERIT(ColoredPoint)         \
                                  \
    OVERRIDE(ColoredPoint3D,draw) \
                                  \
    VAR(read,int,z,JSON(json_int))               \
    /**/
