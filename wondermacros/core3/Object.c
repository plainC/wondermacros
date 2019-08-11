#define NAME Object
#include "x/class_generate.h"

CONSTRUCT
{
    printf("Here\n");
}

Object*
METHOD(eval)(Object* context)
{
    return self;
}

