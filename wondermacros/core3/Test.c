#define UNITTEST_FILE "tests/Test.h"

#undef NAME
#undef CLASS
#define NAME Test
#include "x/class_generate.h"

CONSTRUCT
{
}

void
METHODV(foo)
{
}

void
METHOD(boo)(int x, int y)
{
}

void
METHOD(goo)(int x)
{
}

void Test__foo_s()
{
}

void Test__goo_s()
{
}


#define NAME Test
#include "x/class_vtable.h"
