#include <wondermacros/array/deque.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* deque = NULL;
int is_full;
    W_DEQUE_INIT(deque,3);
    for (int i=0; i < 1000; i++) {
        W_DEQUE_PUSH_BACK(is_full,deque, i);
        if (is_full) {
            printf("Queue full: %d\n", i);
            break;
        }
    }

    W_DEQUE_FOR_EACH_REVERSED(int, t, deque)
        printf("->%d\n", t);

    int x;
    while (!W_DEQUE_IS_EMPTY(deque)) {
        x = W_DEQUE_POP(deque,x);
        printf("%d\n",x);
    }
    W_DEQUE_FREE(deque);
}
