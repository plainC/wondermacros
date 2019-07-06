#include "Nothing.h"
#include "ITest.h"
#include "Point.h"
#include "Point3D.h"

#ifndef WDEBUG_EXPAND
#include <stdio.h>
#include <math.h>
#endif

void foobar(Point* self, int* xx, int x)
{
    printf("jkjkj, context=%d %d\n", *xx, x);
}

int main()
{
    Point* p = W_NEW(Point, .x=1, .y=2);

    printf("%d,%d\n\n", p->x, p->y);
    Point3D* p3 = W_NEW(Point3D, .x=3, .y=4, .z=2);

    printf("%d,%d,%d\n", p3->x, p3->y, p3->z);

    ITestFatPtr testable = W_FAT_PTR_LOOKUP(p,"ITest");
    W_FATCALL(testable,jump)(2);

    ITestFatPtr testable2 = W_FAT_PTR_GET(p3,ITest);
    W_FATCALL(testable2,jump)(2);

    printf("p3 is super of p: %d\n", W_IS_SUPER(p3->klass,p->klass));
    printf("p is super of p3: %d\n", W_IS_SUPER(p->klass,p3->klass));

    printf("p has 'x': %d\n", W_OBJECT_HAS_PROPERTY(p, "x"));
    printf("p has 'z': %d\n", W_OBJECT_HAS_PROPERTY(p, "z"));

    W_FOR_OBJECT_PROPERTY(p,x,int,xp) {
        *xp = 42;
    }

    printf("%d\n", p->x);

    printf("p has 'ITest': %d\n", W_OBJECT_HAS_INTERFACE(p, "ITest"));
    printf("p has 'IFoobar': %d\n", W_OBJECT_HAS_INTERFACE(p, "IFoobar"));

    printf("p eq p3: %d\n", W_CALL(p,eq)((Nothing*) p3));
    printf("p eq p: %d\n", W_CALL(p,eq)((Nothing*) p));

    PropertyRef ref = W_OBJECT_REFERENCE_GET(p, "x");

    int jj=432;
    W_CONNECT(p,ping,foobar,&jj);
    W_EMIT(p,ping,3);

    w_oo_signal_disconnect_all(&p->ping);
    W_CALLV(p,free);
    W_CALLV(p3,free);
}


/*
 * TODO:
 * - constructors
 * - destructors
 * - free
 * - json
 * - Lisp interpreter
 * - reference counting
 * - abstract String class
 *   - String8
 *   - StringTemplate
 */
