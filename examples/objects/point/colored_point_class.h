#define CLASS ColoredPoint
#define SUPER Point

#define BUILD_JSON

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
                                \
    OVERRIDE(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color,JSON(json_string)) \
    /**/
