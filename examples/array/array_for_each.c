#include <stdio.h>
#include <wondermacros/array/array_for_each.h>
#include <wondermacros/array/for_each_reversed.h>

int main()
{
    char foo[] = { 'a', 'b', 'c', 'd', 'e' };

    W_ARRAY_FOR_EACH(char, ch, foo) {
        printf("%d: %c\n", ch_ix, ch);
    }

    printf("\nReversed:\n\n");

    W_ARRAY_FOR_EACH_REVERSED(char, ch, foo) {
        printf("%d: %c\n", ch_ix, ch);
    }
}

