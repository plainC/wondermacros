## Dynamic Stack
    
### W_DYNAMIC_STACK_SIZE(stack)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_SIZE to get the number of elements in the stack.
    
### W_DYNAMIC_STACK_PEEK(stack)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_PEEK to peek the toppest element in the stack.
#### Notes
If the stack is empty, the behaviour is undefined.
    
### W_DYNAMIC_STACK_PEEK_SAFE(stack,value)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
value                A value to be returned if stack is empty
    
```
#### Description
    Use W_DYNAMIC_STACK_PEEK_SAFE to peek the toppest element in the stack.
    If the stack is empty, the given value is returned.
    
### W_DYNAMIC_STACK_POP(array)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_POP to get and remove the last element in the stack.
#### Notes
If the stack is empty, the behavious is undefined.
    
### W_DYNAMIC_STACK_ALLOC_SIZE(stack)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_ALLOC_SIZE to get the current allocation size.
    
### W_DYNAMIC_STACK_IS_EMPTY(stack)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_IS_EMPTY to check if a dynamic stack is empty.
    
### W_DYNAMIC_STACK_INIT(stack,init_size)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
init_size            Initial allocation size for the stack
    
```
#### Description
    Use W_DYNAMIC_STACK_INIT to initialize a dynamic stack.
    
### W_DYNAMIC_STACK_FREE(stack)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_FREE to free a dynamic stack.
    
### W_DYNAMIC_STACK_PUSH(stack,...)
    
#### Arguments
```C
stack                A pointer to a dynamic stack
...                  Values to be pushed into a dynamic stack
    
```
#### Description
    Use W_DYNAMIC_STACK_PUSH to push values to a dynamic stack.
