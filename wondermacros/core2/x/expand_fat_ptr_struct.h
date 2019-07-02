#ifdef INTERFACE

struct W_CAT(CLASS,FatPtr) {
    CLASS* obj;
    W_CLASS_STRUCT_NAME(CLASS)* klass;
};

typedef struct W_CAT(CLASS,FatPtr) W_CAT(CLASS,FatPtr);

#endif /* INTERFACE */

