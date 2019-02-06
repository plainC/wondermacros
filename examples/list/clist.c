#include <stdlib.h>
#include <stdio.h>

#include <wondermacros/list/cslist.h>

struct int_list {
    int value;
    struct int_list* next;
};

static inline struct int_list*
new_list(int value)
{
    struct int_list* self = malloc(sizeof(struct int_list));
    self->value = value;
    self->next = self;
    return self;
}


int main ()
{
    struct int_list* list = NULL;

    struct int_list* a = new_list(1);
    struct int_list* b = new_list(2);
    struct int_list* c = new_list(3);
    struct int_list* d = new_list(4);

    struct int_list* x = new_list(7);
    struct int_list* y = new_list(8);

    W_CSLIST_PREPEND(struct int_list, list, a);
    W_CSLIST_PREPEND(struct int_list, list, b);
    W_CSLIST_PREPEND(struct int_list, list, c);
    W_CSLIST_PREPEND(struct int_list, list, d);

    W_CSLIST_FOR_EACH(struct int_list, l, list)
        printf("%d\n", l->value);

    W_CSLIST_APPEND(struct int_list, x, y);

    printf("\n");

    W_CSLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);

    printf("\n");

    W_CSLIST_PREPEND(struct int_list, list, x);

    W_CSLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);

    return 0;
}

