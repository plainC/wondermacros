#include <stdio.h>
#include <stdlib.h>
#include <wondermacros/array/dynamic_stack.h>


int main()
{
    int* stack;
    W_DYNAMIC_STACK_INIT(stack, 8);
    W_DYNAMIC_STACK_PUSH(stack, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    while (! W_DYNAMIC_STACK_IS_EMPTY(stack))
        printf("%d\n", W_DYNAMIC_STACK_POP(stack));

    W_DYNAMIC_STACK_FREE(stack);
}
