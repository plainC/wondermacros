#include "Nothing.h"
#include "ITest.h"
#include "Point.h"
#include "Point3D.h"

#ifndef WDEBUG_EXPAND
#include <stdio.h>
#include <math.h>
#endif

int main()
{
    Class* klass = (Class*) _none.klass;
    printf("%d\n", W_CALL(klass,is_super)(klass));

    Point* p = W_NEW(Point, .x=1, .y=2);

    printf("%d,%d\n\n", p->x, p->y);
    Point3D* p3 = W_NEW(Point3D, .x=3, .y=4, .z=2);

    printf("%d,%d,%d\n", p3->x, p3->y, p3->z);

//    Point__ITest_FatPtr testable = W_FAT_PTR_GET(p,ITest);
//    W_FATCALL(testable,jump)(2);
}

