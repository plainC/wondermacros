#define INTERFACE_NAME(...)
#define CLASS_NAME(...)
#define METHOD_VOIE(Interface,Scope,RetType,Name) \
    RetType (*Name)();
#define METHOD_WITH_ARGS(Interface,Scope,RetType,Name,Args) \
    RetType (*Name)Args;

struct INTERFACE {
    W_OO_CLASS(__class);
    W_CLASS_EXPAND(CLASS)
};
 
struct W_CAT(INTERFACE,_fat_ptr) {
    struct w_object* obj;
    unsigned offset;
};

typedef struct W_CAT(INTERFACE,_fat_ptr) W_CAT(INTERFACE,FatPtr);

#undef CLASS_NAME
#undef INTERFACE_NAME
#undef METHOD_VOID
#undef METHOD_WITH_ARGS

