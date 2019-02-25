#define W_CLASS_GENERATE
#define INHERIT(...)
#include <wondermacros/objects/x/class.h>
#include <wondermacros/objects/x/object_instance.h>
#include <wondermacros/objects/x/method_forward_declares.h>
#undef W_CLASS_GENERATE

#define W_CLASS_DECLARE
#include <wondermacros/objects/x/class_instance.h>
#undef W_CLASS_DECLARE

#define W_CLASS_GENERATE
#include <wondermacros/objects/x/new.h>
#include <wondermacros/objects/x/dup.h>
#include <wondermacros/objects/x/free.h>
#ifdef BUILD_JSON
# include <wondermacros/objects/x/to_json.h>
#endif

#include <wondermacros/objects/api.h>
#undef W_CLASS_GENERATE
#undef INHERIT

#define CONSTRUCT(C)                  \
    void W_CAT(C,___construct)(struct W_CAT(C,__private)* self)

#define FINALIZE(C)                   \
    void W_CAT(C,___finalize)(struct W_CAT(C,__private)* self)


#define METHOD(C,P,type,...)          \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(C,P,type,__VA_ARGS__)
#define _METHOD_1(C,P,type,name)      \
    _METHOD(C,P,type,name, struct W_CAT(C,__private)* self)
#define _METHOD_2(C,P,type,name,args) \
    _METHOD(C,P,type,name, struct W_CAT(C,__private)* self, BOOST_PP_REMOVE_PARENS(args))
#define _METHOD(C,P,type,name,...) type W_CAT(C,__,name) (__VA_ARGS__)
