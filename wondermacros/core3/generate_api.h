#define TEST(name) \
    void W_CAT(CLASS,__,name)(void)

/***
 *** Name:        W_CALL
 *** Proto:       W_CALL(self,method)(...)
 *** Arg:         self     an object (an instance of a class)
 *** Arg:         method   a method name to be called
 *** Arg:         ...      arguments for the methods
 *** Description: Use W_CALL to call a method of an object with arguments. The macro will expand self automatically as the first argument of the argument list in the method call.
 ***/

#define W_CALL(o,method) \
    (((o)->klass->method) ((void*)(o), W_CALL_CLOSE
#define W_CALL_CLOSE(...) __VA_ARGS__))

#define W_METHOD_CLOSE(...) __VA_ARGS__)
#define METHOD(name) \
    W_CAT(CLASS,__,name)(CLASS* self, W_METHOD_CLOSE
#define METHODV(name) \
    W_CAT(CLASS,__,name)(CLASS* self)

#define CONSTRUCT \
    void W_CAT(CLASS,__user_construct)(CLASS* self)

