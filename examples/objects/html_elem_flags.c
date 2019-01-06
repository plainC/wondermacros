#define META          HTML_ELEM_FLAG_META |
#define INLINE        HTML_ELEM_FLAG_INLINE |
#define BLOCK         HTML_ELEM_FLAG_BLOCK |
#define SELF_CLOSING  HTML_ELEM_FLAG_SELF_CLOSING |
#define EXPERIMENTAL  HTML_ELEM_FLAG_EXPERIMENTAL |
#define DEPRECATED    HTML_ELEM_FLAG_DEPRECATED |

#include "html_elem_type.h"

#define TAG(name,spec) spec 0,
int html_elem_flags[] = {
#include "html_tags.h"
};
#undef TAG

