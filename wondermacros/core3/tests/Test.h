TEST(object_with_simple_property,
        "Create a Test object and set int property 'a'.")
({
    Test* o = W_NEW(Test);
    o->a = 42;
    W_TEST_ASSERT(o->a == 42);
    W_CALLV(o,free);
})
