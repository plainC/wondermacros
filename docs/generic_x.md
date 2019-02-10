## Generic Enum, String Array, and Picked Value Array Generation

Wondermacros provides a few generic X-macros to support meta-programming from compact program forms (specifications).
In order to use these, place the code into a separate file, and use XMACRO(...) form to provide the specification from
which you want to yield the actual C code.  For example, you could write the following into `colors.h':

```C
XMACRO(blue,490)
XMACRO(green,560)
XMACRO(red,700)
XMACRO(violet,450)
XMACRO(yellow,590)
```

### Generic Enum Type Generation

In order to get a simple enumerated type from a specification file, use the following definition and inclusion.
Note that you have to have the `colors.h' from the introduction in the path for the compiler.

```C
#define W_XFILE "colors.h"
#include <wondermacros/x/enum.h>
```

This will yield to:

```C
enum {
    blue,
    green,
    red,
    violet,
    yellow,
};
```

If you want to name the enum, define W_NAME macro before including `<wondermacros/x/enum.h>'. If you need to add a prefix to each
name, specify W_PREFIX. To add a postfix, define W_POSTFIX. If you want to pick XMACRO argument other than the first one (0), specify
W_NAME_INDEX macro with an index number (0..7).

A full example is given here.

```C
#include <stdio.h>

#define W_XFILE "colors.h"
#include <wondermacros/x/enum.h>

int main()
{
    printf("%d %d %d\n", red, green, blue);
}
```

### Generic String Array Generation

In order to get an array of strings from XMACRO specification file, use the following definition and inclusion.
Note that you have to have the `colors.h' from the introduction in the path for the compiler.

```C
#define W_XFILE "colors.h"
#define W_NAME color_names
#include <wondermacros/x/string_name.h>
```
This will yield to:

```C
static const char* color_names[] = {
    "blue",
    "green",
    "red",
    "violet",
    "yellow",
};
```

If you need to add a prefix to each name, specify W_PREFIX. To add a postfix, define W_POSTFIX. If you want to pick XMACRO argument 
other than the first one (0), specify W_NAME_INDEX macro with an index number (0..7).  If you do not want a static array,
define W_STATIC to 0.

### Generic Value Array Generation

In order to get an array of values from XMACRO specification file, use the following definition and inclusion.
Note that you have to have the `colors.h' from the introduction in the path for the compiler.

```C
#define W_XFILE "colors.h"
#define W_TYPE int
#define W_NAME wavelength
#define W_NAME_INDEX 1
#include <wondermacros/x/value_array.h>
```
This will yield to:

```C
static int wavelength[] = {
    490,
    560,
    700,
    450,
    590,
};
```

If you need to add a prefix to each name, specify W_PREFIX. To add a postfix, define W_POSTFIX. If you want to pick XMACRO argument 
other than the first one (0), specify W_NAME_INDEX macro with an index number (0..7).  If you do not want a static array,
define W_STATIC to 0.
