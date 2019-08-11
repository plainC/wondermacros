#include "Nothing.h"
#include "ITest.h"
#include "Point.h"
#include "Point3D.h"
#include "StdoutWriter.h"

#ifndef WDEBUG_EXPAND
#include <stdio.h>
#include <math.h>
#endif

/**/

int
int32__to_json (int32_t* self, IWriter * writer, void *context)
{
    char buf[256];
    sprintf(buf, "%d", *self);
    W_ICALL (IWriter, writer, append) (buf, strlen(buf));
}

static struct w_oo_meta int32_meta = {
    .name = "int32_t",
    .size = sizeof (int32_t),
};

Class int32__class_instance = {
    ._meta = (void *) &int32_meta,
    .to_json = (void*) int32__to_json,
};

// size_t

int
size_t__to_json (size_t* self, IWriter * writer, void *context)
{
    char buf[256];
    sprintf(buf, "%zd", *self);
    W_ICALL (IWriter, writer, append) (buf, strlen(buf));
}

static struct w_oo_meta size_t_meta = {
    .name = "size_t",
    .size = sizeof (size_t),
};

Class size_t__class_instance = {
    ._meta = (void *) &size_t_meta,
    .to_json = (void*) size_t__to_json,
};

// cstring
int
cstring__to_json (const char* self, IWriter * writer, void *context)
{
    W_ICALL (IWriter, writer, append) ((char*)self, strlen(self));
}

static struct w_oo_meta cstring_meta = {
    .name = "cstring",
    .size = sizeof(char*),
};

Class cstring__class_instance = {
    ._meta = (void *) &cstring_meta,
    .to_json = (void*) cstring__to_json,
};
/**/


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

    W_ICALLV(ITest,p,fooo);

    int jj=432;
    W_CONNECT(p,ping,foobar,&jj);
    W_EMIT(p,ping,3);

    StdoutWriter* out = W_NEW(StdoutWriter);
    W_CALL(p,to_json)((IWriter*) out, NULL);

    W_CALLV(p,free);
    W_CALLV(p3,free);

/*
    ITestFatPtr testable = W_FAT_PTR_LOOKUP(p,"ITest");
    W_FATCALL(testable,jump)(2);

    ITestFatPtr testable2 = W_FAT_PTR_GET(p3,ITest);
    W_FATCALL(testable2,jump)(2);


    printf("p eq p3: %d\n", W_CALL(p,eq)((Nothing*) p3));
    printf("p eq p: %d\n", W_CALL(p,eq)((Nothing*) p));

    PropertyRef ref = W_OBJECT_REFERENCE_GET(p, "x");

    w_oo_signal_disconnect_all(&p->ping);
*/
}


/*
 * TODO:
 * - json
 * - Lisp interpreter
 * - reference counting
 * - abstract String class
 *   - String8
 *   - StringTemplate
 */
