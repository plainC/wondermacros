#include <wondermacros/array/move_left.h>
#include <wondermacros/array/move_right.h>
#include <stdio.h>

int main()
{
    int array[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    W_ARRAY_MOVE_LEFT(array, 10, 5, 3);
    for (int i=0; i < 10-3; i++)
        printf("%d: %d\n", i, array[i]);

printf("---\n");
    int array2[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    W_ARRAY_MOVE_RIGHT(array2, 10, 5, 3);
    for (int i=0; i < 10+3; i++)
        printf("%d: %d\n", i, array2[i]);

}

