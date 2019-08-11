extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct W_CAT(CLASS,__class) W_CAT(CLASS,__class_instance);
extern struct UnitTest W_CAT(CLASS,__tests)[];

#if HAS_CONSTRUCT
void W_CAT(CLASS,__user_construct)(CLASS* self);
#endif

