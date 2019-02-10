#include <stdio.h>

#define W_XFILE "colors.h"
#include <wondermacros/x/enum.h>

#define W_XFILE "colors.h"
#define W_TYPE int
#define W_NAME wavelength
#define W_NAME_INDEX 1
#include <wondermacros/x/value_array.h>

int main()
{
    printf("%d %d %d\n", wavelength[red], wavelength[green], wavelength[blue]);
}

