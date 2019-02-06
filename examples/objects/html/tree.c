#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <stdlib.h>
# include <wondermacros/compiler/unused.h>
# include <wondermacros/array/for_each.h>
# include <wondermacros/array/dynamic_array.h>
# include <wondermacros/array/dynamic_stack.h>
#endif
# include <wondermacros/tree/for_each.h>

#include "tree.h"

#include "tree_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(tree)
{
}

FINALIZE(tree)
{
}

METHOD(tree,public,int,to_string,
    (struct model* model, struct view_context* context))
{

    struct quad_tree {
        double value;
        struct quad_tree* next[4];
    };

    struct quad_tree* tree = W_CALL(model,get)(self->name);
    if (tree) {
        W_TREE_FOR_EACH_POSTORDER(struct quad_tree, node, tree) {
            W_CALL(model,bind_ptr)("@elem",1,&node->value);
            W_CALL(self->child,to_string)(model, context);
        }
    }

    return 0;
}


#include <wondermacros/objects/x/class_end.h>
