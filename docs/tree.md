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
Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
    Also define what stack is to be used by defining PUSH_PTR(p), PEEK_PTR(), SWAP_PTRS(ix1,ix2) and POP_PTR() macros.
    Stack needs to be available before calling this macro and it must
    have space for the depth of the tree, or have the capability to grow.
    
### W_TREE_FOR_EACH_POSTORDER(T,node,self)
#### Arguments
```C
T                    type name of tree nodes
node                 name of the free variable
self                 a tree
```
#### Description
    Use W_TREE_FOR_EACH_POSTORDER to traverse a tree structure iteratively in postorder.
#### Notes
Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
    
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
