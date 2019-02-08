#define CLASS ColoredPoint

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
                                \
    OVERLOAD(ColoredPoint,draw) \
                                \
    VAR(read,const char*,color) \
    /**/
