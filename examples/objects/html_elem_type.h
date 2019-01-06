#ifndef __HTML_ELEM_TYPE_H
#define __HTML_ELEM_TYPE_H

#include <wondermacros/meta/cat.h>

enum html_elem_type {
#define TAG(name,spec) W_CAT(html_elem_type_,name),
#include "html_tags.h"
#undef TAG
};

enum html_elem_flags {
    HTML_ELEM_FLAG_SELF_CLOSING = 1,
    HTML_ELEM_FLAG_BLOCK = 2,
    HTML_ELEM_FLAG_INLINE = 4,
    HTML_ELEM_FLAG_META = 8,
    HTML_ELEM_FLAG_DEPRECATED = 16,
    HTML_ELEM_FLAG_EXPERIMENTAL = 32,
};

extern int html_elem_flags[];

#endif

