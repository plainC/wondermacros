#include "Object.h"


#define NAME Writer
#include "x/class_generate.h"

CONSTRUCT
{
}

bool
METHOD(put_char)(char ch)
{
    printf("%c", ch);
}

bool
METHOD(put_cstr)(const char* str)
{
    printf("%s", str);
}

#define NAME Writer
#include "x/class_vtable.h"

