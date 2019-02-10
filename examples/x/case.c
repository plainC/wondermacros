#include <stdio.h>

#define W_XFILE "colors.h"
#include <wondermacros/x/enum.h>

#define W_XFILE "colors.h"
#define W_NAME color_name
#include <wondermacros/x/string_name.h>

void warm(int color)
{
    printf("%s is warm\n", color_name[color]);
}

void cold(int color)
{
    printf("%s is cold", color_name[color]);
}

int main()
{
    int color = red;

    switch (color) {
#   define W_XFILE "colors.h"
#   define W_NAME_INDEX 0
#   define W_CODE_INDEX 2
#   define W_CODE_PREFIX printf("Let's see\n");
#   define W_CODE_POSTFIX printf("Or is it?\n");
#   include <wondermacros/x/case.h>
    }
}
