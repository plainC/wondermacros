#include <stdio.h>
#include <stdlib.h>

#define W_XFILE "colors.h"
#define W_NAME color
#define W_PREFIX
#include <wondermacros/x/enum.h>


#define W_XFILE "colors.h"
#define W_NAME_INDEX 0
#define W_CODE_INDEX 3
#define W_COMMON enum color color; int r : 8; int g : 8; int b : 8;
#include <wondermacros/x/struct.h>

int main()
{
    struct blue* b = malloc(sizeof(struct blue));
    b->color = blue;
    b->r = 0;
    b->g = 0;
    b->b = 255;

    free(b);
}
