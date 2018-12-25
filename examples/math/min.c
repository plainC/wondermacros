#include <stdio.h>
#include <string.h>
#include <wondermacros/math/max.h>
#include <wondermacros/math/min.h>

int main()
{
    printf("%d\n", W_MIN(4,6,2,7));
    printf("%d\n", W_MIN(2,6,4,7));
    printf("%d\n", W_MIN(6,2,4,7));
    printf("%d\n", W_MIN(7,6,4,2));

    printf("%d\n", W_MAX(4,6,2,7));
    printf("%d\n", W_MAX(2,6,4,7));
    printf("%d\n", W_MAX(6,2,4,7));
    printf("%d\n", W_MAX(7,6,4,2));
}
