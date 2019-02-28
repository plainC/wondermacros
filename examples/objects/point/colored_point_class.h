#define CLASS ColoredPoint

#define BUILD_JSON

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
    INHERIT(Point)              \
                                \
    OVERRIDE(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color,JSON(json_string)) \
    /**/
