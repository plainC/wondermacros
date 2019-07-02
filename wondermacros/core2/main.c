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
    Point* p = W_NEW(Point, .x=1, .y=2);

    printf("%d,%d\n\n", p->x, p->y);
    Point3D* p3 = W_NEW(Point3D, .x=3, .y=4, .z=2);

    printf("%d,%d,%d\n", p3->x, p3->y, p3->z);

    ITestFatPtr testable = W_FAT_PTR_GET(p,ITest);
    W_FATCALL(testable,jump)(2);

    ITestFatPtr testable2 = W_FAT_PTR_GET(p3,ITest);
    W_FATCALL(testable2,jump)(2);

/*

    printf("p3 is super of p: %d\n", W_CALL(p3->klass,is_super)((Class*) (p->klass)));
    printf("p is super of p3: %d\n", W_CALL(p->klass,is_super)((Class*) (p3->klass)));
*/
//    printf("p eq p3: %d\n", W_CALL(p,eq)((Nothing*) p3));
//    printf("p eq p: %d\n", W_CALL(p,eq)((Nothing*) p));
}


/*
 * TODO:
 * - has interface
 * - json
 * - Lisp interpreter
 * - reference counting
 * - abstract String class
 *   - String8
 *   - StringTemplate
 */
