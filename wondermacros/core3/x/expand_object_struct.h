#define CLASS_NAME(...)
#define INTERFACE_NAME(...)
#define VAR(name,type,dims,klass,key_class,class_arg) \
    type name dims;
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(name)                                 \
    int (**name)(CLASS* self, void* arg);
#define SIGNAL(name,args)                             \
    int (**name)(CLASS* self, BOOST_PP_REMOVE_PARENS(args), void* arg);


struct CLASS {
    W_OBJECT_INTERFACE;
    W_CAT_OUTER(CLASS,__define)
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

