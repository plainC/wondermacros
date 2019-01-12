#include "Iplotting.h"

#undef SUPER
#define SUPER Point
#undef CLASS
#define CLASS Point2D
#define Point2D__is_abstract 0

#define Point2D__inherited_interfaces \
    Point__inherited_interfaces


#define Point2D__private_properties
#define Point2D__public_properties \
    Point__public_properties       \
    PROPERTY(int,x)                \
    PROPERTY(int,y)                \
    /* End */

#define Point2D__public_methods    \
    Point__public_methods
#define Point2D__private_methods
#define Point2D__override_methods  \
    I__plotting(Point2D)           \
    /* End */
