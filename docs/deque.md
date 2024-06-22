## Deque
    
### W_DEQUE_INIT(Q,alloc_size)
#### Arguments
```C
Q                    a pointer to a deque.
alloc_size           initial allocation size
```
#### Description
    Use W_DEQUE_INIT to initialize a deque. The given size is rounded up to next power of two.
    
### W_DEQUE_RESIZE(T,Q,new_size)
#### Arguments
```C
Q                    a pointer to a deque.
new_size             new allocation size
```
#### Description
    Use W_DEQUE_RESIZE to resize a deque. The given size is rounded up to next power of two.
    
### W_DEQUE_FREE(Q)
#### Arguments
```C
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_FREE to free a deque.
    
### W_DEQUE_SIZE(Q)
#### Arguments
```C
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_SIZE to get the number of elements in a deque.
    
### W_DEQUE_GET_SIZE(Q)
#### Arguments
```C
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_GET_SIZE to get the number of elements in a deque. If Q is NULL, the size is zero.
    
### W_DEQUE_IS_EMPTY(Q)
#### Arguments
```C
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_IS_EMPTY to test if a deque is empty.
    
### W_DEQUE_POP_FRONT(Q,element)
#### Arguments
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
#### Description
    Use W_DEQUE_POP_FRONT to get pop an element from the front of a deque.
    
### W_DEQUE_POP_BACK(Q,element)
#### Arguments
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
#### Description
    Use W_DEQUE_POP_BACK to get pop an element from the back of a deque.
    
### W_DEQUE_POP(Q,element)
#### Arguments
```C
Q                    a pointer to a deque.
element              an identifier where the fetched element is stored
```
#### Description
    Use W_DEQUE_POP to get pop an element from a deque.
    
### W_DEQUE_PUSH_BACK(Q,...)
#### Arguments
```C
Q                    a pointer to a deque.
...                  elements to be pushed to the queue
```
#### Description
    Use W_DEQUE_PUSH_BACK to push elements back of a deque. The expression return NULL if the queue is full, the queue itself otherwise.
    
### W_DEQUE_PUSH_FRONT(Q,...)
#### Arguments
```C
Q                    a pointer to a deque.
...                  elements to be pushed to the queue
```
#### Description
    Use W_DEQUE_PUSH_FRONT to push elements front of a deque. If queue is full, NULL is returned.
    
### W_DEQUE_CLEAR(Q)
#### Arguments
```C
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_CLEAR to clear a deque (without freeing it).
    
### W_DEQUE_FOR_EACH(T,e,Q)
#### Arguments
```C
T                    a type name.
e                    a free identifier
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_FOR_EACH to iterate all elements in a deque.
#### Example
```C
'W_DEQUE_FOR_EACH(int,x,deque) printf("%d\n", x);'.
```
    
### W_DEQUE_FOR_EACH_REVERSED(T,e,Q)
#### Arguments
```C
T                    a type name.
e                    a free identifier
Q                    a pointer to a deque.
```
#### Description
    Use W_DEQUE_FOR_EACH_REVERSED to iterate all elements in a deque in reversed order.
#### Example
```C
'W_DEQUE_FOR_EACH_REVERSED(int,x,deque) printf("%d\n", x);'.
```
    
### W_DEQUE_PEEK(Q[,n])
#### Arguments
```C
Q                    a pointer to a deque.
n                    index starting from the front of the queue.
```
#### Description
    Use W_DEQUE_PEEK to peek an element in deque.
    
### W_DEQUE_PEEK_FRONT(Q[,n])
#### Arguments
```C
Q                    a pointer to a deque.
n                    index starting from the front of the queue.
```
#### Description
    Use W_DEQUE_PEEK_FRONT to peek an element in deque.
    
### W_DEQUE_PEEK_BACK(Q[,n])
#### Arguments
```C
Q                    a pointer to a deque.
n                    index starting from the back of the queue.
```
#### Description
    Use W_DEQUE_PEEK_BACK to peek an element in deque.
