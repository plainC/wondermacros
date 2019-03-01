#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/misc/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
#endif


/* Include class header. */
#include "model.h"

/* Begin class implementation. */
#include "model_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(model) /* self */
{
    self->variables = NULL;
}

FINALIZE(model) /* self */
{
    W_ARRAY_FOR_EACH(struct variable*,var, self->variables) {
        free((void*) var->name);
        free(var);
    }
}

METHOD(model,public,void*,get,
    (const char* name))
{
    W_ARRAY_FOR_EACH(struct variable*,var, self->variables, W_DYNAMIC_ARRAY_GET_SIZE(self->variables))
        if (strcmp(var->name, name) == 0)
            return var->ptr;
    return NULL;
}

METHOD(model,public,int,bind_ptr,
    (const char* name, int type, void* ptr))
{
    struct variable* var = malloc(sizeof(struct variable));
    var->name = strdup(name);
    var->type = type;
    var->ptr = ptr;

    W_ARRAY_FOR_EACH(struct variable*,v, self->variables, W_DYNAMIC_ARRAY_GET_SIZE(self->variables))
        if (strcmp(v->name, name) == 0) {
            free(v);
            self->variables[v_ix] = var;
            return 1;
        }

    W_DYNAMIC_ARRAY_PUSH(self->variables, var);
    return 0;
}

#include <wondermacros/objects/x/class_end.h>
