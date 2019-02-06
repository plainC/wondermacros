#include <stdlib.h>
#include <stdio.h>

#include <wondermacros/list/dlist.h>

struct int_list {
    int value;
    struct int_list* next;
    struct int_list* prev;
};

static inline struct int_list*
new_list(int value, struct int_list* prev, struct int_list* next)
{
    struct int_list* self = malloc(sizeof(struct int_list));
    self->value = value;
    self->next = next;
    self->prev = prev;
    return self;
}


int main ()
{
    struct int_list* list = NULL;

    struct int_list* a = new_list(1, NULL, NULL);
    struct int_list* b = new_list(2, NULL, NULL);

    struct int_list* x = new_list(7, NULL, NULL);
    struct int_list* y = new_list(8, NULL, NULL);

    W_DLIST_APPEND(struct int_list, list, a);
    W_DLIST_APPEND(struct int_list, list, b);
    W_DLIST_APPEND(struct int_list, x, y);

    W_DLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);
    printf("\n");

    W_DLIST_PREPEND(struct int_list, list, x);

    W_DLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);

    return 0;
}

