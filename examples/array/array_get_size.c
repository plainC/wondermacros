#include <stdio.h>
#include <wondermacros/array/get_size.h>

int main()
{
    char foo[] = { 'a', 'b', 'c' };
    printf("%d\n", W_ARRAY_GET_SIZE(foo));
}

