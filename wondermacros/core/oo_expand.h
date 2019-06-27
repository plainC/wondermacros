#ifdef EXTERN
# define IS_HEADER 0
#else
# define IS_HEADER 1
# define EXTERN extern
#endif


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

#ifdef CLASS
# include "oo_x_macros/expand_class_struct.h"
# include "oo_x_macros/expand_class_instance.h"
# include "oo_x_macros/expand_object_struct.h"
# include "oo_x_macros/expand_common_methods.h"
#endif


#undef METHOD
#undef _METHOD_1
#undef _METHOD_2

#if IS_HEADER
#undef CLASS
#undef NAME
#endif

#undef ABSTRACT
#undef SINGLETON
#undef INTERFACE
#undef KIND

#undef IS_HEADER
#undef EXTERN

#define METHOD(Name) W_CAT(CLASS,__,Name)
