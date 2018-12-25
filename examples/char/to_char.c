#include <stdio.h>
#include <string.h>
#include <wondermacros/char/to_char.h>

int main()
{
    char buf[] = { W_TO_CHAR(a), W_TO_CHAR(b), W_TO_CHAR(c), W_TO_CHAR(7), 0 };

    printf("%s\n", buf);
}
