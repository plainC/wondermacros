#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
#include <wondermacros/meta/declare.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>
# define W_OBJECT_CAST_TO_VOID
# include <wondermacros/objects/api.h>
#endif

#include "point.h"
#include "colored_point.h"
#include "colored_point3d.h"
#include "owner.h"

#include <wondermacros/objects/json/int.c>
#include <wondermacros/objects/json/string.c>
#include <wondermacros/objects/json/object.c>
#include <wondermacros/objects/json/int_array_2.c>

int main()
{
    struct Point* array[] = {
        W_NEW(Point),
        W_NEW(ColoredPoint),
        W_NEW(ColoredPoint3D, .x=5, .y=2, .z=8, .color="green"),
    };

#include <wondermacros/meta/stringize.h>
#define VAR(name,value) "\"" # name "\":" W_STRINGIZE(value)

    const char* json = "{"
        "\"r\":[1,2],"
        VAR(x,12) "," VAR(y,99) ",\"a\": {" VAR(id,77) "," VAR(number,88) " }"
    "},"
    "{"
        VAR(x,1) "," VAR(y,2) ","
        VAR(color,"black")
    "}";

#undef VAR

    const char* end;
    /* We will initialize the first two objects from JSON string. */
printf("%s\n", json);
    if (W_CALL(array[0],from_json)(json, &end))
        printf("ERROR: %d\n", end-json);

    if (W_CALL(array[1],from_json)(end, &end))
        printf("ERROR\n");

    /* A buffer for JSON output. */
    char buffer[256];

    for (int i=0; i < 3; i++) {
        printf("Round: %d\n", i);
        W_ARRAY_FOR_EACH(struct Point*, point, array) {
            if (W_CALL(point,to_json)(buffer,256) < 0)
                printf("Error\n");
            else
                printf("%s\n", buffer);
            W_CALL_VOID(point,draw);
            W_CALL(point,move_up)(2);
        }
    }
}
