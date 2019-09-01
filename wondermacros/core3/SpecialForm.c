#include "oo_types.h"

#include "Object.h"


#define NAME SpecialForm
#include "x/class_generate.h"

Object*
METHOD(eval_special)(Object* args, EvalContext* context)
{
    return self;
}

#define NAME SpecialForm
#include "x/class_vtable.h"
