#define EXTERN

#include "oo_api.h"

/*** Include superclass */
#include "Point.h"
/**/
/*** Expand Point3D */
#include "Point3D__class.h"
#include "oo_expand_begin.h"
/**/

void
METHOD(shout)(ITestFatPtr self, int i)
{
    printf("SHOUT %d:\n",i*2);
}

/**/
#include "oo_expand_vtable.h"
