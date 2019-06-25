/*
 * X-macro simplifiers.
 */
#undef METHOD
#define METHOD(Interface,Scope,RetType,...) \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(Interface,Scope,RetType,__VA_ARGS__)
#define _METHOD_1(...) METHOD_VOID(__VA_ARGS__)
#define _METHOD_2(...) METHOD_WITH_ARGS(__VA_ARGS__)


struct CLASS;
typedef struct CLASS CLASS;

#ifdef INTERFACE
# include "oo_x_macros/expand_interface_struct.h"
#endif

#ifdef CLASS
# include "oo_x_macros/expand_class_struct.h"
# include "oo_x_macros/expand_class_instance.h"
# include "oo_x_macros/expand_object_struct.h"
#endif


#undef METHOD
#undef _METHOD_1
#undef _METHOD_2

#undef W_IS_PUBLIC

#define METHOD(Name) W_CAT(CLASS,__,Name)
