/*
 * This file contains all expansions which are done before defining CLASS to CLASS##__private.
 */

static const char* class_name = W_STRINGIZE(CLASS);
struct W_CAT(CLASS,__private__class);
extern struct W_CAT(CLASS,__private__class) W_CLASS_INSTANCE_NAME(W_CAT(CLASS,__private));
struct W_CAT(CLASS,__class)* W_CLASS_INSTANCE_NAME(CLASS) = (void*) &W_CLASS_INSTANCE_NAME(W_CAT(CLASS,__private));
