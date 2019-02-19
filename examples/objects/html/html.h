#ifndef __HTML_H
#define __HTML_H

struct view_context {
    char* buffer;
    size_t size;
    int pos;
};

#include "classes_declare.h"
#define W_OBJECT_CAST_TO_VOID

#include "model.h"

#include "html_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif

