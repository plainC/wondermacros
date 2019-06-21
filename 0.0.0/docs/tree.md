## Trees
    
### W_TREE_FOR_EACH_PREORDER(T,node,self)
#### Arguments
```C
T                    type name of tree nodes
node                 name of the free variable
self                 a tree
```
#### Description
    Use W_TREE_FOR_EACH_PREORDER to traverse a tree structure iteratively in preorder.
#### Notes
Redefine W_TREE_NEXT(node,ix), W_TREE_GET_DEGREE(node) and W_REVERSED to get correct behaviour with any tree type.
    
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
