#define CLASS ColoredPoint

#define BUILD_JSON

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
    INHERIT(Point)              \
                                \
    OVERLOAD(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color,JSON(json_string)) \
    /**/
