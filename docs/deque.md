## Deque
    
### W_DEQUE_FREE(Q)
```C
Q                    a pointer to a deque.
```
    Use W_DEQUE_FREE to free a deque.
    
### W_DEQUE_SIZE(Q)
```C
Q                    a pointer to a deque.
```
    Use W_DEQUE_SIZE to get the number of elements in a deque.
    
### W_DEQUE_IS_EMPTY(Q)
```C
Q                    a pointer to a deque.
```
    Use W_DEQUE_IS_EMPTY to test if a deque is empty.
    
### W_DEQUE_POP_FRONT(Q,element)
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
    Use W_DEQUE_POP_FRONT to get pop an element from the front of a deque.
    
### W_DEQUE_POP_BACK(Q,element)
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
    Use W_DEQUE_POP_BACK to get pop an element from the back of a deque.
    
### W_DEQUE_POP(Q,element)
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
    Use W_DEQUE_POP to get pop an element from a deque.
    
### W_DEQUE_PUSH_BACK(is_full,Q,...)
```C
is_full              an integer variable to be assigned.
Q                    a pointer to a deque.
...                  elements to be pushed to the queue
```
    Use W_DEQUE_PUSH_BACK to push elements back of a deque. 'is_full' is assigned 1 if queue is full.
    
### W_DEQUE_PUSH_FRONT(is_full,Q,...)
```C
is_full              an integer variable to be assigned.
Q                    a pointer to a deque.
...                  elements to be pushed to the queue
```
    Use W_DEQUE_PUSH_FRONT to push elements front of a deque. 'is_full' is assigned 1 if queue is full.
    
### W_DEQUE_CLEAR(Q)
```C
Q                    a pointer to a deque.
```
    Use W_DEQUE_CLEAR to clear a deque (without freeing it).
    
### W_DEQUE_INIT(Q,alloc_size)
```C
Q                    a pointer to a deque.
alloc_size           exponent of two
```
    Use W_DEQUE_INIT to initialize a deque. The size is given as a power of two (i.g. 4 means size 16).
    
### W_DEQUE_FOR_EACH(T,e,Q)
```C
T                    a type name.
e                    a free identifier
Q                    a pointer to a deque.
```
    Use W_DEQUE_FOR_EACH to iterate all elements in a deque.
    
### W_DEQUE_FOR_EACH_REVERSED(T,e,Q)
```C
T                    a type name.
e                    a free identifier
Q                    a pointer to a deque.
```
    Use W_DEQUE_FOR_EACH to iterate all elements in a deque in reversed order.
    
### W_DEQUE_PEEK_FRONT(Q[,n])
```C
Q                    a pointer to a deque.
n                    index starting from the front of the queue.
```
    Use W_DEQUE_PEEK_FRONT to peek an element in deque.
    
### W_DEQUE_PEEK_BACK(Q[,n])
```C
Q                    a pointer to a deque.
n                    index starting from the back of the queue.
```
    Use W_DEQUE_PEEK_BACK to peek an element in deque.
