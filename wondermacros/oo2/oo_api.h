#ifndef __OO_API_H
#define __OO_API_H

#define W_PP_IS_UNARY(...) \
    BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1)

#define W_EAT(...)

/***
 *** Name:        W_NEW
 *** Proto:       W_NEW(T [,...])
 *** Arg:         T     a class name
 *** Arg:         ...   values to be set (e.g. W_NEW(point, .x=1, .y=2))
 *** Description: Use W_NEW to create (and to initialize) an object.
 ***/
#define W_NEW(...) (                                                             \
    ((void*) BOOST_PP_IF(W_PP_IS_UNARY(__VA_ARGS__),                             \
        W_CAT(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),__new)(NULL,NULL),           \
        _W_NEW(__VA_ARGS__)                                                      \
    )                                                                            \
)
#define _W_NEW(T,...)                                                            \
    ((void*) W_CAT(T,__new)(NULL,&((struct W_CAT(T)){__VA_ARGS__}))))

#define W_CALLV(o,method) \
    (((o)->klass->method)((void*)(o)))



#define W_TEST_ASSERT(cond) \
    do { \
        if (!(cond)) { \
            printf("[%s:%d] { %s }", __FILE__, __LINE__, # cond); \
            return 1; \
        } \
    } while (0)

#define W_UNITTEST(klass)                                  \
    do {                                                   \
        printf("Unittest: %s\n", # klass);                 \
        for (int i=0; W_CAT(klass,__tests)[i].name; i++) { \
            printf("  %s: ", W_CAT(klass,__tests[i].name));  \
            if (W_CAT(klass,__tests)[i].func(NULL)) {      \
                printf(" failed\n");                       \
            } else {                                       \
                printf("ok\n");                           \
            }                                              \
        }                                                  \
    } while (0)


#endif
