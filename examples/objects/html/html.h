#ifndef __HTML_H
#define __HTML_H

struct view_context {
    char* buffer;
    size_t size;
    int pos;
};

#include "classes_declare.h"

#include "model.h"

#include "html_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif

