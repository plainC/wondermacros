#undef TEST

#ifdef UNITTEST_FILE
# define EXPECT_TEST_CASE(code) \
    code \
    return 0; \
    }
# define TEST(name,...) \
    static int W_CAT(CLASS,__test__,name)(void* context) \
    { EXPECT_TEST_CASE
# include UNITTEST_FILE
# undef TEST
# undef EXPECT_TEST_CASE
#endif

struct UnitTest W_CAT(CLASS,__tests)[] = {
#ifdef UNITTEST_FILE
# define TEST(Name,...) {.func = W_CAT(CLASS,__test__,Name),.name=#Name }, W_EAT
# include UNITTEST_FILE
# undef UNITTEST_FILE
#endif
    {NULL,NULL}
};
