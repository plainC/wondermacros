## Object-Oriented Programming in C

### Introduction
There exists various libraries for object-oriented programming in C, e.g.
[GObject](https://developer.gnome.org/gobject/stable/).  There are also
compilers, pre-processors and tools which will build objects for C.  In
Wondermacros we will take a different approach.  We will use a header file
(e.g. a_class.h) which has a fixed-form and specific guidelines 
to define a class with properties and methods.  Then we will create another
header file (e.g. a.h) which includes the first header and an
X-macro, <wondermacros/objects/x_macro_expand_h.h>. This header may also
have other type definitions and declarations just like all headers if needed.
Then we will implement the methods of the class in a separate C file (e.g.
a.c). This C file also includes the first header (a_class.h) and
an X-macro, <wondermacros/objects/x_macro_expand_c.h>.  This set-up will
give us object-oriented capabilities including:

* Abstraction: we have class based objects with properties and methods
* Encapsulation: we have public, private and read-only properties, public and private methods
* Inheritance: we have single inheritance
* Polymorphism: method calls lookup the actual method implementation from the class of the object being called
* Introspection: we can study existing objects at runtime

### How to define a class
In order to define a class, first create a new header file, e.g. 'point_class.h'.
The first thing is to name the class.  We name it to 'Point' by defining CLASS macro.

```C
#define CLASS Point
```

Next we declare the superclass, properties and method of this class. This is done by
defining Point__define macro.

```C
#define Point__define                                         \
    /* Inherits */                                            \
    /*none */                                                 \
                                                              \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,private,void,ping,(const char* message))     \
    METHOD(Point,public,void,draw)                            \
                                                              \
    VAR(read,int,x)                                           \
    VAR(read,int,y)                                           \
    /**/

```

Since this class is the superclass we do not inherit anything. 
Each method is defined inside `METHOD(class_name,scope,return_type,method_name,method_args)` macro.
The class name has to be present in each definition (i.g. Point in our example). `scope' can be
public or private.  `return_type` is the return type of the method, `method_name` is the name of the
method and method's arguments are given inside parenthisis after it.  If the method
does not take arguments give only the first four arguments to METHOD.

Properties are defined using VAR macro. The first argument specifies the scope which is private, read, or
public.  Read means read-only so x and y can only be modified in the implementation of Point's methods.

### How to inherit a class

Next we will define a class `ColoredPoint` in `colored_point_class.h`.  It will inherit the previously
defined `Point` class. The code is underneath.

```C
#define CLASS ColoredPoint

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
                                \
    OVERLOAD(ColoredPoint,draw) \
                                \
    VAR(read,char*,color)       \
    /**/
```

We place Point__define as the first declaration to specify the inheritance. Next we declare draw method
to be overloaded in ColoredPoint. The last line adds a color property which is read-only.

### How to expand the header file of a class

What we have now is just the plain definitions of two classes. In order to compile code we need to
get the necessary type definitions and forward declarations in C.  And then actually implement the
class. Typically classess refer to each other so they need forward declarations of each other before
the types are actually declared. In our simple example this is not actually needed but we will cover it
here anyway. In order to get the forward declarations we write the following into `classes_declare.h':

```C
#ifndef __CLASSES_DECLARE_H
#define __CLASSES_DECLARE_H

#include "point_class.h"
#include <wondermacros/objects/x/forward_declare.h>

#include "colored_point_class.h"
#include <wondermacros/objects/x/forward_declare.h>

#endif
```

Next we create `point.h'.

```C
#ifndef __POINT_H
#define __POINT_H

#include "classes_declare.h"

#include "point_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif
```

In the subclass's header in `colored_point.h' we must include `point.h'. These header may include
other declarations if they are needed in the implementations.

```C
#ifndef __COLORED_POINT_H
#define __COLORED_POINT_H

#include "classes_declare.h"

#include "point.h"

#include "colored_point_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif
```

### How to implement a class

In order to implement the class we will first include the header file of the class, i.g. `point.h'.
The next step is to include the class file `point_class.h' and the X-macro which begins the class
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
`FINALIZE`.  Each method is implemented using `METHOD` macro. Note that the name of the class must be
repeated in each method. The object in all methods including constructor and destructor can be accessed in `self'.
A method of an object can be called using `W_CALL' or `W_CALL_VOID'.

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

We created objects using W_NEW macro. It is defined, as well as other generic object macros, in `<wondermacros/objects/api.h>`.
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

### Source code and other examples

The source code of the previous example can be found 
[here](https://github.com/plainC/wondermacros/tree/master/examples/objects/point). There is 
[another example](https://github.com/plainC/wondermacros/tree/master/examples/objects/html) which
implements a simple web content generation classes (HTML elements, HTML attributes, strings and simple string templates).

```C
int main()
{
    char* script =
        "var x, y, z;"
        "x = 1;"
        "y = 8;"
        "z = x + y;"
        ""
        "document.getElementById(\"demo\").innerHTML ="
        "\"The value of z is \" + z + \".\";";

    int v=42;
    double e=2.744;
    double* prices = NULL;
    int has_prices = 0;

    W_DYNAMIC_ARRAY_PUSH(prices, 2.12, 3.14, 6.32, 4.24, 7.44);

    struct model* model = W_NEW(model);
    W_CALL(model,bind_ptr)("has_prices",0,&has_prices);
    W_CALL(model,bind_ptr)("a",0,&v);
    W_CALL(model,bind_ptr)("e",1,&e);
    W_CALL(model,bind_ptr)("prices",1,prices);


    struct html_elem* doc = DOC(
        DOCTYPE,
        htmlHTML( attrID(_("FooPoro")), attrLANG(_("fi-FI")), attrDIR(_("LTR")), attrCLASS(_("Public")),
            htmlHEAD(
                htmlMETA(attrCHARSET(_("utf-8"))),
                htmlMETA(attrHTTP_EQUIV(_("X-UA-Compatible")), attrCONTENT(_("IE=Edge,chrome=1"))),
                htmlMETA(attrNAME(_("viewport")), attrCONTENT(_("width=device-width, initial-scale=1"))),
                htmlBASE(attrHREF(_("https://local.com/"))),
                htmlTITLE(_("First page"))
            ),
            htmlBODY(
                css(cssTYPE_SELECTOR("p"),"width:9;"),
            ),
            INT_VAR("a"), DOUBLE_VAR("e", .format="%.2%%"), COND("has_prices", ARRAY("prices", htmlLI(htmlB(DOUBLE_VAR("@elem", .format="$%.2f")))))
        )
    );


    char buffer[1024];
    int pos=0;

    struct view_context context;
    context.buffer = buffer;
    context.size = 1024;
    context.pos = 0;

    W_CALL(doc,to_string)(model, &context);
    printf("%s\n", buffer);
}
```
