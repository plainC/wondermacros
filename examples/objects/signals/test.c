#include <wondermacros/objects/api.h>
#include <stdio.h>
#include <stdlib.h>

#include "point.h"

void
my_cb(struct Point* self, void* data, int steps)
{
    printf(" Moved: %d steps\n",steps);
}

void
my_cb2(struct Point* self, void* data, int steps)
{
    printf(" Yes it dit move %d\n",steps);
}

int main()
{
    struct Point* p = W_NEW(Point, .x=3, .y=7);
    W_OBJECT_SIGNAL_TYPE* handle;

    W_CONNECT(p,on_move,my_cb, handle);
    W_CONNECT(p,on_move,my_cb2, handle);
    W_CALL_VOID(p,draw);
    W_CALL(p,move_up)(2);
    W_CALL_VOID(p,draw);

    W_DISCONNECT(handle);
    W_CALL(p,move_up)(1);

    W_CALL_VOID(p,free);
}

