#include <stdio.h>
#include <stdlib.h>
#include <wondermacros/array/dynamic_array.h>
#include <wondermacros/array/array_for_each.h>


int main()
{
    int* array = NULL;
//    W_DYNAMIC_ARRAY_INIT(array, int, 8);
    W_DYNAMIC_ARRAY_PUSH(array, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    W_ARRAY_FOR_EACH(int, elem, array, W_DYNAMIC_ARRAY_SIZE(array)) {
        printf("%d\n", elem);
    }

    /* Or simply */
    printf("-----\n");
    for (int i=0; i < W_DYNAMIC_ARRAY_SIZE(array); i++)
        printf("%d\n", array[i]);

    printf("Last elem=%d (steal it)\n", W_DYNAMIC_ARRAY_STEAL_LAST(array));
    printf("Last elem=%d (using safe version)\n", W_DYNAMIC_ARRAY_PEEK_LAST_SAFE(array,0));
    printf("Remove two elements starting at position 3\n");

    W_DYNAMIC_ARRAY_REMOVE(array, 3, 2);
    for (int i=0; i < W_DYNAMIC_ARRAY_SIZE(array); i++)
        printf("%d: %d\n", i, array[i]);

    W_DYNAMIC_ARRAY_FREE(array);
}
