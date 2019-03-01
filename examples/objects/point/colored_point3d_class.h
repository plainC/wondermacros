#define CLASS ColoredPoint3D
#define SUPER ColoredPoint

#define BUILD_JSON

#define ColoredPoint3D__define    \
    /* Inherits */                \
    ColoredPoint__define          \
                                  \
    OVERRIDE(ColoredPoint3D,draw) \
                                  \
    VAR(read,int,z,JSON(json_int))               \
    /**/
