extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct UnitTest W_CAT(CLASS,__tests)[];

#if HAS_CONSTRUCT
void W_CAT(CLASS,__user_construct)(CLASS* self);
#endif


#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(...)
#define METHODV(C,is_member,type,name)                        \
    BOOST_PP_IF(is_member,                                    \
        type W_CAT(CLASS,__,name)(C* self);,                  \
        type W_CAT(CLASS,__,name)();)                         \
    /**/
#define METHOD(C,is_member,type,name,args) \
    BOOST_PP_IF(is_member,                                    \
        type W_CAT(CLASS,__,name)(C* self, BOOST_PP_REMOVE_PARENS(args));, \
        type W_CAT(CLASS,__,name)(BOOST_PP_REMOVE_PARENS(args));)          \
    /**/
#define SIGNALV(...)
#define SIGNAL(...)

W_CAT_OUTER(CLASS,__define)

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

