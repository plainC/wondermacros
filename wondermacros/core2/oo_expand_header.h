#undef EXTERN
#undef IS_HEADER
#define EXTERN extern
#define IS_HEADER

#include "oo_api.h"
#include "x/define_x_macro_simplifiers.h"
#include "x/expand_class_struct.h"
#include "x/expand_object_struct.h"
#include "x/expand_declare_methods.h"
#include "x/expand_class_instance.h"
#include "x/expand_common_methods.h"

#undef IS_HEADER
#undef EXTERN
#undef CLASS
