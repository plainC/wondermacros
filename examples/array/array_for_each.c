#include <stdio.h>
#include <wondermacros/array/array_for_each.h>

int main()
{
    char foo[] = { 'a', 'b', 'c', 'd', 'e' };

    W_ARRAY_FOR_EACH(char, ch, foo) {
        printf("%d: %c\n", ch_ix, ch);
    }
}

