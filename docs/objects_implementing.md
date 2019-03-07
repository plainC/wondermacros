### How to implement a class

In order to implement the class we will first include the header file of the class, i.g. `point.h`.
The next step is to include the class file `point_class.h` and the X-macro which begins the class
implementation. The implementation is written between two X-macros. The file must end to another
X-macro inclusion. See an example bellow.

```C
#ifndef WDEBUG_EXPAND
# include <stdio.h>
# include <wondermacros/compiler/unused.h>
#endif


/* Include class header. */
#include "point.h"

/* Begin class implementation. */
#include "point_class.h"
#include <wondermacros/objects/x/class_start.h>


CONSTRUCT(Point) /* self */
{
    W_CALL(self,ping)("constructed");
    W_UNUSED(self);
}

FINALIZE(Point) /* self */
{
    W_UNUSED(self);
}

METHOD(Point,private,void,ping,(const char* message))
{
    printf("Message: %s\n", message);
}


METHOD(Point,public,int,move_up,(int steps))
{
    if (self->y - steps < 0) {
        W_CALL(self,ping)("Hits the wall");
        self->y = 0;
        return 1;
    }

    self->y -= steps;
    return 0;
}

METHOD(Point,public,int,move_left,(int steps))
{
    self->x -= steps;
    return 0;
}

METHOD(Point,public,void,draw)
{
    printf("point at %d,%d\n", self->x, self->y);
}


#include <wondermacros/objects/x/class_end.h>
```

A constructor is provided in a block after `CONSTRUCT` macro, and a destructor in a similar manner after
`FINALIZE`. If you need to call the constructor of a superclass, you can use `W_CALL_CONSTRUCT` macro.
For example, to call the constructor of Point in Point3D, add `W_CALL_CONSTRUCT(Point)` into the body
of the constructor of `Point3D`. To call destructor in finalize block, use `W_CALL_FINALIZE(class_name)`.

If your class does not need a constructor, add `#define NO_CONSTRUCT` into the class definition file.
To notify missing destructor, define `#define NO_DESTRUCT`.

Each method is implemented using `METHOD` macro. Note that the name of the class must be
repeated in each method. The object in all methods including constructor and destructor can be accessed in `self`.
A method of an object can be called using `W_CALL` or `W_CALL_VOID`.

