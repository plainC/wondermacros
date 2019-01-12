#include "Iplotting.h"

#undef SUPER
#undef CLASS
#define CLASS Point
#define Point__is_abstract 1

#define Point__public_properties
#define Point__inherited_interfaces \
    I__plotting(Point)  \
    /* End */
#define Point__public_methods
