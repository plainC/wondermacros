#ifndef __HTML_ELEM_TYPE_H
#define __HTML_ELEM_TYPE_H

#include <wondermacros/meta/cat.h>

enum html_elem_type {
#define TAG(name,spec) W_CAT(html_elem_type_,name),
#include "html_tags.h"
};

#endif

