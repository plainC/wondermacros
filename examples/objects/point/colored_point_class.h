#define CLASS ColoredPoint

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
    INHERIT(Point)              \
                                \
    OVERLOAD(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color) \
    /**/
