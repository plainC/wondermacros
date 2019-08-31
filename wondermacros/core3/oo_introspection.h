#ifndef W_OO_INTROSPECTION_H
#define W_OO_INTROSPECTION_H

#include <string.h>


static inline void*
w_oo_lookup_method(Class* klass, const char* name)
{
    for (int i=0; klass->methods[i].name; i++) {
printf("%s %s\n", klass->methods[i].name, name);
        if (strcmp(klass->methods[i].name, name) == 0)
            return klass->methods[i].func;
    }

    return NULL;
}

static inline struct ClassProperty*
w_oo_lookup_property(Class* klass, const char* name)
{
    for (int i=0; klass->properties[i].name; i++)
        if (strcmp(klass->properties[i].name, name)==0)
            return &klass->properties[i];

    return NULL;
}

#endif

