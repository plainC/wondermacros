#include <stdio.h>
#include <string.h>
#include <wondermacros/pp_char/to_char.h>

int main()
{
    char buf[] = {
        W_PP_CHAR_TO_CHAR(a),
        W_PP_CHAR_TO_CHAR(b),
        W_PP_CHAR_TO_CHAR(c),
        W_PP_CHAR_TO_CHAR(7),
        0
     };

    printf("%s\n", buf);
}
