#include <wondermacros/array/deque.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* deque = NULL;
    W_DEQUE_INIT(deque,3);
    for (int i=0; i < 1000; i++) {
        if (!W_DEQUE_PUSH_BACK(deque, i)) {
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
