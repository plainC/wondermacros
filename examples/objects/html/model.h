#ifndef __MODEL_H
#define __MODEL_H

struct variable {
    const char* name;
    int type;
    void* ptr;
};

#include "classes_declare.h"

#include "model_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif

