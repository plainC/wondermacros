#ifndef WDEBUG_EXPAND
# include <wondermacros/array/dynamic_array.h>
#endif

TEST(object_with_simple_property,
        "Create a Test object and set an int property 'a'.")
({
    Test* o = W_NEW(Test);
    o->a = 42;
    W_TEST_ASSERT(o->a == 42);
    W_CALLV(o,free);
})

TEST(object_with_array_property,
        "Create a Test object and set an int array property 'b'.")
({
    Test* o = W_NEW(Test);

    for (int i=0; i < sizeof(o->b)/sizeof(o->b[0]); i++)
        o->b[i] = i;

    for (int i=0; i < sizeof(o->b)/sizeof(o->b[0]); i++)
        W_TEST_ASSERT(o->b[i] == i);

    W_CALLV(o,free);
})

TEST(object_with_2_dim_array_property,
        "Create a Test object and set a two dimensional int array property 'c'.")
({
    Test* o = W_NEW(Test);

    for (int i=0; i < sizeof(o->c)/sizeof(o->c[0]); i++)
        for (int j=0; j < sizeof(o->c[j])/sizeof(o->c[j][0]); j++)
            o->c[i][j] = i*100 + j;

    for (int i=0; i < sizeof(o->c)/sizeof(o->c[0]); i++)
        for (int j=0; j < sizeof(o->c[j])/sizeof(o->c[j][0]); j++)
            W_TEST_ASSERT(o->c[i][j] == i*100 + j);

    W_CALLV(o,free);
})


TEST(object_with_dynamic_array_property,
        "Create a Test object and set a dynamic int array property 'd'.")
({
    Test* o = W_NEW(Test);
    o->e = NULL;
    W_TEST_ASSERT(W_DYNAMIC_ARRAY_GET_SIZE(o->e) == 0);

    W_DYNAMIC_ARRAY_PUSH(o->e, 1, 2, 3, 4, 5, 6, 7, 8);
    W_TEST_ASSERT(W_DYNAMIC_ARRAY_GET_SIZE(o->e) == 8);

    int i=0;
    W_DYNAMIC_ARRAY_FOR_EACH(int, elem, o->e)
        W_TEST_ASSERT(elem == ++i);

    W_CALLV(o,free);
})
