#include <wondermacros/sorting/variadic_testing.h>

#undef COMPARE
#define COMPARE strcmp


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
    printf("is in equal: %d\n", W_VARIADIC_IS_EQUAL("a","a","a"));
    printf("is in equal: %d\n", W_VARIADIC_IS_EQUAL("a","b","c"));
    printf("is in ascending order: %d\n", W_VARIADIC_IS_IN_ASC_ORDER("a","b","c"));
    printf("is in ascending order: %d\n", W_VARIADIC_IS_IN_ASC_ORDER("a","c","b"));

    return 0;
}
