#include <stdio.h>
#include <stdlib.h>
#include <wondermacros/array/dynamic_array.h>
#include <wondermacros/array/array_for_each.h>

#undef W_GET
#define W_GET(array,ix) W_DYNAMIC_ARRAY_ELEM(array,ix)

int main()
{
    W_DYNAMIC_ARRAY_DECLARE(int, array);
    W_DYNAMIC_ARRAY_INIT(array, int, 8);

    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    W_ARRAY_FOR_EACH(int, elem, array, W_DYNAMIC_ARRAY_SIZE(array)) {
        printf("%d\n", elem);
    }

    W_DYNAMIC_ARRAY_CLEAR(array);
}

