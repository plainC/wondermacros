#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(C,is_member,type,name)                        \
    BOOST_PP_IF(is_member,                                    \
        type (*name)(C* self);,                               \
        type (*name)();)                                      \
    /**/
#define METHOD(C,is_member,type,name,args) \
    BOOST_PP_IF(is_member,                                    \
        type (*name)(C* self, BOOST_PP_REMOVE_PARENS(args));, \
        type (*name)(BOOST_PP_REMOVE_PARENS(args));)          \
    /**/
#define SIGNALV(...)
#define SIGNAL(...)

struct CLASS;
typedef struct CLASS CLASS;

struct W_CAT(CLASS,__class) {
    W_CLASS_INTERFACE;
    W_CAT_OUTER(CLASS,__define)
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

