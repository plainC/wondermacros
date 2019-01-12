#include "point.h"
#include "point2d.h"
#include "point3d.h"
#include <wondermacros/array/for_each.h>
#include <wondermacros/objects/api.h>
#include <wondermacros/compiler/ref_void_ptr.h>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <wondermacros/compiler/byte_offset.h>



int main ()
{
    struct Point* points[] = {
        (struct Point*) W_NEW(Point2D, .x=6),
        (struct Point*) W_NEW(Point3D, .x=1, .y=2, .z=9),
    };

    W_ARRAY_FOR_EACH(struct Point*, p, points)
        W_CALL(p,plot_colored)("black");

    printf("\nMethods of points[0]'s class (%s):\n", W_OBJECT_CLASS_NAME(points[0]));
    for (int i=0; W_OBJECT_METHOD_BY_INDEX(points[0],i); i++)
        printf(" * %s\n", W_OBJECT_METHOD_BY_INDEX(points[0],i));
    printf("\n");

#define METHOD_PLOT_COLORED void (*)(struct Point*,const char*)

    W_ARRAY_FOR_EACH(struct Point*, p, points)
        W_CALL_VOID(p,free);

    return 0;
}
