#include <stdlib.h>
#include <stdio.h>
#include <wondermacros/tree/for_each.h>

struct bintree {
    struct bintree* next[2];
    const char* value;
};

static inline struct bintree*
tree_new(const char* value)
{
    struct bintree* t = malloc(sizeof(struct bintree));

    t->value = value;
    t->next[0] = t->next[1] = NULL;
    return t;
}

#define LEFT 0
#define RIGHT 1

int main()
{
    struct bintree* a = tree_new("a");
    struct bintree* b = tree_new("b");
    struct bintree* c = tree_new("c");
    struct bintree* d = tree_new("d");
    struct bintree* e = tree_new("e");

    a->next[LEFT] = b;
    a->next[RIGHT] = e;
    b->next[LEFT] = c;
    c->next[LEFT] = d;

    void** stack = NULL;

    printf("In preorder:\n");
    W_TREE_FOR_EACH_PREORDER(struct bintree, node, a)
        printf("%s\n", node->value);

    W_DYNAMIC_STACK_FREE(stack);

    printf("In postorder:\n");
    W_TREE_FOR_EACH_POSTORDER(struct bintree, node, a)
        printf("%s\n", node->value);

    W_DYNAMIC_STACK_FREE(stack);
}

