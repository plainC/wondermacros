#define CLASS_NAME(Name) (Class*) &W_CAT(Name,__class_instance),
#define INTERFACE_NAME(...)
#define VAR(...)
#define OVERRIDE(...)
#define METHODV(...)
#define METHOD(...)
#define SIGNALV(...)
#define SIGNAL(...)


Class* W_CAT(CLASS,__superclasses)[] = {
    W_CAT_OUTER(CLASS,__define)
    NULL
};

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef VAR
#undef OVERRIDE
#undef METHODV
#undef METHOD
#undef SIGNALV
#undef SIGNAL

