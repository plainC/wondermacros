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

#undef W_REVERSED
#define W_REVERSED 0
#define PUSH_PTR(p) W_DYNAMIC_STACK_PUSH(stack, p)
#define POP_PTR() W_DYNAMIC_STACK_POP(stack)
#define PEEK_PTR() W_DYNAMIC_STACK_PEEK(stack)
#define SWAP_PTRS(x, y) W_DYNAMIC_ARRAY_SWAP(void*, stack, x, y)

    void** stack = NULL;

    printf("In preorder:\n");
    W_TREE_FOR_EACH_PREORDER(struct bintree, node, a)
        printf("%s\n", node->value);

    W_DYNAMIC_STACK_FREE(stack);

#define PUSH_TAGGED_PTR(p,t) W_DYNAMIC_STACK_PUSH(stack, (void*) ((uintptr_t)(p) | ((uintptr_t)(((t)&1)))))
#define POP_TAGGED_PTR(t) (t=(uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&1, (void*)((uintptr_t)W_DYNAMIC_STACK_POP(stack)&(~1ull)))
#define PEEK_TAGGED_PTR(t) (t=(uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&1, (void*)((uintptr_t)W_DYNAMIC_STACK_PEEK(stack)&(~1ull)))

    printf("In postorder:\n");
    W_TREE_FOR_EACH_POSTORDER(struct bintree, node, a)
        printf("%s\n", node->value);

    W_DYNAMIC_STACK_FREE(stack);
}

