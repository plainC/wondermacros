struct CLASS;
typedef struct CLASS CLASS;

struct W_CLASS_STRUCT_NAME(CLASS);
typedef struct W_CLASS_STRUCT_NAME(CLASS) W_CLASS_STRUCT_NAME(CLASS);

#ifdef INTERFACE
struct W_CAT(CLASS,FatPtr);
typedef struct W_CAT(CLASS,FatPtr) W_CAT(CLASS,FatPtr);
#endif // INTERFACE
