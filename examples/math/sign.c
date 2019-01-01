#include <stdio.h>
#include <string.h>
#include <wondermacros/math/sign.h>

int main()
{
    printf(" 2->%d\n", W_SIGN(2));
    printf(" 0->%d\n", W_SIGN(0));
    printf("-2>%d\n", W_SIGN(-2));
}
