## Unit Testing

Wondermacros itself has build-in unit tests which use an X-macro based unit tester.
All you need to do is to create a C file, define W_XFILE to include all source code
to be tested, and then include `<wondermacros/x/unit_test.h>'. It will expand to a
main program that can be compiled. See an example below.

```C
#include <string.h>
#define W_XFILE <wondermacros/all.h>
#include <wondermacros/x/unit_test.h>
```

The tests are written to the header files to be included. The best place is at the
end of the file. There, first test if W_TEST is not defined. If it is not, define
it to expand to nothing. Then add tests separately. See an example below.

```C
/*Unit Test*/

#ifndef W_TEST
# define W_TEST(...)
#endif

W_TEST(W_ID,
    int W_ID(i) = 42;
    W_TEST_ASSERT(W_ID(i) == 42, "Value mismatch");
)
```

    
### W_TEST(name,...)
#### Arguments
```C
name                 name of the test case
...                  statements to be executed
```
#### Description
    Use W_TEST to add a unit test directly into a header file.  It is used with the unit test X-Macro.
    
### W_TEST_ASSERT(cond,...)
#### Arguments
```C
cond                 a condition expression, should evaluate to non-zero if test ok
...                  format and arguments for error reporting
```
#### Description
    Use W_TEST_ASSERT to run a test in a unit test.
    
### W_TEST_GROUP(name)
#### Arguments
```C
name                 a test group name
```
#### Description
    Use W_TEST_GROUP to group tests in unit testing.
