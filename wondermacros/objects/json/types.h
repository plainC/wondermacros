#ifndef __W_OBJECT_JSON_TYPES_H
#define __W_OBJECT_JSON_TYPES_H

#ifndef WDEBUG_EXPAND
# include <stdlib.h>
#endif

struct w_json_class {
    int (*to_string)(void* self, char* buffer, size_t size);
    int (*from_string)(const char* buffer, const char** endptr, void* self);
};

#endif

