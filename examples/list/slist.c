#include <stdlib.h>
#include <stdio.h>

#include <wondermacros/list/slist.h>

struct int_list {
    int value;
    struct int_list* next;
};

static inline struct int_list*
new_list(int value, struct int_list* next)
{
    struct int_list* self = malloc(sizeof(struct int_list));
    self->value = value;
    self->next = next;
    return self;
}


int main ()
{
    struct int_list* list = NULL;

    struct int_list* a = new_list(1, NULL);
    struct int_list* b = new_list(2, NULL);

    struct int_list* x = new_list(7, NULL);
    struct int_list* y = new_list(8, NULL);

    W_SLIST_APPEND(struct int_list, list, a);
    W_SLIST_APPEND(struct int_list, list, b);
    W_SLIST_APPEND(struct int_list, x, y);

    W_SLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);
    printf("\n");

    W_SLIST_PREPEND(struct int_list, list, x);

    W_SLIST_FOR_EACH(struct int_list, l, x)
        printf("%d\n", l->value);

    return 0;
}

