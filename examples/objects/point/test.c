#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
#include <wondermacros/meta/declare.h>
# include <stdio.h>
# define W_OBJECT_CAST_TO_VOID
# include <wondermacros/objects/api.h>
#endif

#include "point.h"
#include "colored_point.h"
#include "colored_point3d.h"

extern struct w_json_class Point__property_type[];

int
json_type_int_to_string(int* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%d", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_type_int_from_string(const char* buffer, size_t size, int** self)
{
    return 0;
}

int
json_type_string_to_string(char** self, char* buffer, size_t size)
{
    int len = strlen(*self);
    if (len+2 >= size)
        return -1;
    *buffer++ = '\"';
    strncpy(buffer, *self, len);
    buffer += len;
    *buffer++ = '\"';
    return len+2;
}

int
json_type_string_from_string(const char* buffer, size_t size, void** self)
{
    return 0;
}


int main()
{
    struct Point* array[] = {
        W_NEW(Point, .x = 2, .y = 7),
        W_NEW(ColoredPoint, .x = 4, .y = 9, .color = "red"),
        W_NEW(ColoredPoint3D, .x=5, .y=2, .z=8, .color="green"),
    };

    char buffer[256];

    for (int i=0; i < 3; i++) {
        printf("Round: %d\n", i);
        W_ARRAY_FOR_EACH(struct Point*, point, array) {
            W_CALL(point,to_json)(buffer,256);
            printf("%s\n", buffer);
            W_CALL_VOID(point,draw);
            W_CALL(point,move_up)(2);
        }
    }
}
