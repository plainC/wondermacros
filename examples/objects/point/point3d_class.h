#include "Iplotting.h"

#undef SUPER
#define SUPER Point2D
#undef CLASS
#define CLASS Point3D
#define Point3D__is_abstract 0

#define Point3D__inherited_interfaces \
    Point2D__inherited_interfaces

#define Point3D__public_properties \
    Point2D__public_properties \
    PROPERTY(int,z) \
    /* End */
#define Point3D__private_properties \
    /* End */

#define Point3D__public_methods \
    Point2D__public_methods
#define Point3D__private_methods
#define Point3D__override_methods \
    I__plotting__plot_colored(Point3D) \
    /* End */
