## Trees
    
### W_TREE_FOR_EACH_PREORDER(T,node,self)
#### Arguments
```C
T                    type name of tree nodes
node                 name of the free variable
TreeRoot             a tree (root node)
```
#### Description
    Use W_TREE_FOR_EACH_PREORDER to traverse a tree structure iteratively in preorder.
#### Notes
Specify the stack to be used by including a configuration file under "wondermacros/configs/stack".
    By default a static array stack is used and the stack size is set in WCONF_STACK_SIZE.
    
### W_TREE_FOR_EACH_POSTORDER(T,node,TreeRoot)
#### Arguments
```C
T                    type name of tree nodes
node                 name of the free variable
TreeRoot             a tree
```
#### Description
    Use W_TREE_FOR_EACH_POSTORDER to traverse a tree structure iteratively in postorder.
#### Notes
Specify the stack to be used by including a configuration file under "wondermacros/configs/stack".
    By default a static array stack is used and the stack size is set in WCONF_STACK_SIZE.
    
### W_TREE_FOR_EACH_LEVELORDER(T, node, TreeRoot)
#### Arguments
```C
T                    type name of tree nodes
node                 name of the free variable
TreeRoot             a tree
```
#### Description
    Use W_TREE_FOR_EACH_LEVELORDER to traverse a tree structure iteratively in levelorder.
#### Notes
Specify the stack to be used by including a configuration file under "wondermacros/configs/stack".
    By default a static array stack is used and the stack size is set in WCONF_STACK_SIZE.
    
### W_TREE_FREE(T,self)
#### Arguments
```C
T                    type name of tree nodes
self                 a tree
```
#### Description
    Use W_TREE_FREE to free all nodes in a tree.
#### Notes
Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
    Also define what stack is to be used by defining WCONF_STACK_DECLARE_AND_INIT, WCONF_STACK_FREE, WCONF_STACK_PUSH_PTR(p), WCONF_STACK_PEEK_PTR(), WCONF_STACK_SWAP_PTRS(ix1,ix2) and WCONF_STACK_POP_PTR() macros.
    Stack needs to be available before calling this macro and it must
    have space for the depth of the tree, or have the capability to grow.
    If these macros are not defined before including for_each.h,
    dynamic stack is used by default.
