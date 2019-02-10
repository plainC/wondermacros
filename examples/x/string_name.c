#include <stdio.h>

#define W_XFILE "colors.h"
#include <wondermacros/x/enum.h>

#define W_XFILE "colors.h"
#define W_NAME color_names
#include <wondermacros/x/string_name.h>

int main()
{
    printf("%s %s %s\n", color_names[red], color_names[green], color_names[blue]);
}

