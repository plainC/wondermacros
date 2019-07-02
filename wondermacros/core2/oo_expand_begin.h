#undef EXTERN
#undef IS_HEADER
#define EXTERN

#include "oo_api.h"
#include "x/define_x_macro_simplifiers.h"
#include "x/expand_class_struct.h"
#include "x/expand_object_struct.h"
#include "x/expand_declare_methods.h"
#include "x/expand_common_methods.h"

#undef EXTERN
#undef _METHOD_2
#undef _METHOD_1
#undef METHOD

/* In source file, expand METHOD as a method name with class name as a prefix. */
#define METHOD(Name) W_CAT(CLASS,__,Name)
