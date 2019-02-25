#ifndef __W_OBJECT_JSON_TYPES_H
#define __W_OBJECT_JSON_TYPES_H

#ifndef WDEBUG_EXPAND
# include <stdlib.h>
#endif

struct w_json_class {
    int (*to_string)(void* self, char* buffer, size_t size);
    int (*from_string)(const char* buffer, size_t size, void** self);
};

int json_type_int_to_string(int* self, char* buffer, size_t size);
int json_type_int_from_string(const char* buffer, size_t size, int** self);
int json_type_string_to_string(char** self, char* buffer, size_t size);
int json_type_string_from_string(const char* buffer, size_t size, void** self);

#endif

