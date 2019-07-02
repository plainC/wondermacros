/*
 * Common settings for all expansions.
 */

/*
 * X-macro simplifiers.
 */
#undef METHOD
#define METHOD(Interface,RetType,...) \
    BOOST_PP_OVERLOAD(_METHOD_,__VA_ARGS__)(Interface,RetType,__VA_ARGS__)
#define _METHOD_1(...) METHOD_VOID(__VA_ARGS__)
#define _METHOD_2(...) METHOD_WITH_ARGS(__VA_ARGS__)


#undef API
#define API(Interface,RetType,...) \
    BOOST_PP_OVERLOAD(_API_,__VA_ARGS__)(Interface,RetType,__VA_ARGS__)
#define _API_1(...) API_VOID(__VA_ARGS__)
#define _API_2(...) API_WITH_ARGS(__VA_ARGS__)
