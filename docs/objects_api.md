### How to declare and create an object

An object of class `Point` is declared `struct Point* a;`, for instance. If
you prefer to avoid writting `struct` each time, define `USE_T_TYPE_SUFFIX`
macro before including `<wondermacros/x/forward_declare.h>`. It will declare
a type `Point_t` which can be used instead.

To create an object use `W_NEW` macro. It will take the class name as the
first argument. All, or just selected, public and read-only properties can be
initialized with `W_NEW`. For example, `W_NEW(Point, .x=3, .y=8)` creates
a `Point` object where properties x and y are set. If some of the properties
are not initialized, they are set to zero.

### How to call methods of an object

Let's now put it all together and provide a test program. We will also implement `ColoredPoint3D` in a similar way.
See the full source code of the example in here.

```C
#include <wondermacros/array/for_each.h>

#ifndef WDEBUG_EXPAND
#include <wondermacros/meta/declare.h>
# include <stdio.h>
# include <wondermacros/objects/api.h>
#endif

#include "point.h"
#include "colored_point.h"
#include "colored_point3d.h"


int main()
{
    struct Point* array[] = {
        W_NEW(Point, .x = 2, .y = 7),
        W_NEW(ColoredPoint, .x = 4, .y = 9, .color = "red"),
        W_NEW(ColoredPoint3D, .x=5, .y=2, .z=8, .color="green"),
    };

    for (int i=0; i < 3; i++) {
        printf("Round: %d\n", i);
        W_ARRAY_FOR_EACH(struct Point*, point, array) {
            W_CALL_VOID(point,draw);
            W_CALL(point,move_up)(2);
        }
    }
}
```

We created objects using `W_NEW` macro. It is defined, as well as other generic object macros, in `<wondermacros/objects/api.h>`.
Its first argument is the class name and after that we can provide the initial
values including read-only properties.  The syntax is the structure initialization syntax, so
if property names are omitted the order of values must be the same than in the class definition (not recommended to
omit).

A method call is invoked by `W_CALL` macro. It takes two arguments, an object and a method name and it expects an
argument list to follow (e.g. `W_CALL(o,method)(1,2)`.  It then expands to `((o)->klass->method)` and goes to the
argument list and adds the object as the first argument, e.g. `(o, 1,2)`.  If the method does not take any arguments
(except the automatically added object itself), use `W_CALL_VOID(o,method);` instead.  Note that `W_CALL` cannot
be used in a macro definition, e.g. `#define EVAL_AND_ADD(o,context,x) W_CALL(o,eval)(context) + (x)` does not work.
You have to expand all calls manually in macro definitions, e.g.
`#define EVAL_AND_ADD(o,context),x) (((o)->klass->eval)(o,context) + (x))`.

It is also possible to create object without initialization.  Use `ColoredPoint_new()` to create `ColoredPoint` object.  If
you want to clone an existing object `b`, use `ColoredPoint_new_with(b)`.  All these object creations run the constructor.

To finalize and free an object `o`, run `ColoredPoint_free(o)`. It will first run the destructor block and then free the
object's memory allocation.


