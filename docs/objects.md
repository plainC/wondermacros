## Object-Oriented Programming in C

### Introduction
There exists various libraries for object-oriented programming in C, e.g.
[GObject](https://developer.gnome.org/gobject/stable/).  There are also
compilers, pre-processors and tools which will build objects for C.  In
Wondermacros we will take a different approach.  We will use a header file
(e.g. `a_class.h`) which has a fixed-form and specific guidelines 
to define a class with properties and methods.  Then we will create another
header file (e.g. `a.h`) which includes the first header and an
X-macro, `<wondermacros/objects/x_macro_expand_h.h>`. This header may also
have other type definitions and declarations just like all headers if needed.
Then we will implement the methods of the class in a separate C file (e.g.
a.c). This C file also includes the first header (a_class.h) and
an X-macro, `<wondermacros/objects/x_macro_expand_c.h>`.  This set-up will
give us object-oriented capabilities including:

* Abstraction: we have class based objects with properties and methods
* Encapsulation: we have public, private and read-only properties, public and private methods
* Inheritance: we have single inheritance
* Polymorphism: method calls lookup the actual method implementation from the class of the object being called
* Introspection: we can study existing objects at runtime

We also introduce a tool which creates all necessary boilerplate automatically
from [simple class specifications](https://github.com/plainC/wondermacros/blob/master/examples/objects/vechiles/classes.wobject).

### How to define a class
In order to define a class, first create a new header file, e.g. `point_class.h`.
The first thing is to name the class.  We name it to `Point` by defining CLASS macro.

```C
#define CLASS Point
```

Next we declare the superclass, properties and method of this class. This is done by
defining `Point__define` macro.

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
The class name has to be present in each definition (i.g. `Point` in our example). `scope` can be
`public` or `private`.  `return_type` is the return type of the method, `method_name` is the name of the
method and method's arguments are given inside parenthisis after it.  If the method
does not take arguments give only the first four arguments to `METHOD`.

Properties are defined using `VAR` macro. The first argument specifies the scope which is private, read, or
public.  Read means read-only so `x` and `y` can only be modified in the implementation of Point's methods.
When we have created instances of a class, properties can be accessed directly by
`object->property`. Private properties are hidden in the public struct with a prefix. If `USE_GCC_EXTENSION_COUNTER`
macro is defined also the name is hidden. In the implementation file, where X-macro `<wondermacros/objects/x/class_start.h>`
is expanded, the private properties are visible. In a similary way, read-only properties get `const` definition
in the public structure.

### How to inherit a class

Next we will define a class `ColoredPoint` in `colored_point_class.h`.  It will inherit the previously
defined `Point` class. The code is underneath.

```C
#define CLASS ColoredPoint
#define SUPER Point

#define ColoredPoint__define    \
    /* Inherits */              \
    Point__define               \
                                \
    OVERRIDE(ColoredPoint,draw) \
                                \
    VAR(read,char*,color)       \
    /**/
```

We place `Point__define` as the first declaration to specify the inheritance. Next we declare draw method
to be overrided in `ColoredPoint`. The last line adds a color property which is read-only.
Note that we also define macro `SUPER`. It is not used in generating the actual
class, so `Point__define` must be the first declaration. `SUPER` macro is, however,
used in filling the meta-data of the class, and in various other places, such
as in generating UML class diagram from source code. Thus, it must be there
even though things might work without it.

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

Next we create `point.h`.

```C
#ifndef __POINT_H
#define __POINT_H

#include "classes_declare.h"

#include "point_class.h"
#include <wondermacros/objects/x/class_declare.h>

#endif
```

In the subclass's header in `colored_point.h` we must include `point.h`. These header may include
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

### Abstract classes

In order to define an abstract class, add `#define ABSTRACT` into the class
definition file. An abstract class does not need to implement
a constructor or a destructor, and `W_NEW` cannot create instances of that
class.

### Common superclass

Some object-oriented languages have a common superclass for all classes.
To get a common superclass just include `<wondermacros/objects/object.h>` in a
header of the project. By default, it will create a type called `struct Object`
which can be used as a superclass for all objects. If you prefer a lowercase
name, define `LOWERCASE_OBJECT` macro before the inclusion. If you prefer
`Object_t`, define `USE_T_TYPE_SUFFIX`. Both of them can be combined to get
`object_t`.

### Array properties and bit fields

It is possible to declare a fixed size array property using additional declaration with `Array(...)` macro.
For example, `VAR(public,int,items,Array(2))` declares one-dimensional array of two integers. Multi-dimensional
arrays are defined by adding dimensions to `Array` macro.

Sometimes we might want to save space, and declare properties with bit field length. For example,
`VAR(public,unsigned,tiny,Bits(3))` declares a property taking just three bits. This, however, saves space only
when multiple properties are delared sequentially and they fit into a word boundary. Note that to use bit fields
you must define `#define USE_BIT_FIELDS` in the class file, and JSON serialization cannot be used for that class.

### JSON Serialization and Marshalling

Objects can be automatically serialized to JSON strings and marshalled from JSON as well. To build JSON support
for a class add `#define BUILD_JSON` to the class file. Each property which is chosen to be including in JSON
serialization and marshaling must be marked as such using the fourth argument position in `VAR` macro. The
prefix of the C function which does the conversion must be given there inside `JSON(<function prefix>)` macro.
For example, `VAR(public,int,x,JSON(json_int))` works for `int` type. Use `JSON(json_string)` for `const char*`
and so on.

The JSON conversion callbacks must be linked into the exceutable. Many of these exists under 
[objects/json directory](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/) (e.g.
JSON conversion for [int](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/int.c).

| C Type      | 4th argument to VAR    | As JSON         |
| ----------- | ---------------------- | --------------- |
| Any object  | JSON(json_object)      | { ... }         |
| bool        | JSON(json_bool)        | true or false   |
| int         | JSON(json_boolean)     | true or false   |
| int         | JSON(json_int)         | ]-2^31, 2^31[   |
| int64_t     | JSON(json_int64)       | ]-2^63, 2^63[   |
| unsigned    | JSON(json_unsigned)    | [0, 2^32[       |
| uint64_t    | JSON(json_unsigned64)  | [0, 2^64[       |
| char        | JSON(json_char)        | [0,255]         |
| string      | JSON(json_string)      | "..."           |
| float       | JSON(json_float)       | 32 bit float    |
| double      | JSON(json_double)      | 64 bit float    |
| long double | JSON(json_long_double) | 80 bit float    |

If none of the types in the previous table does not apply, JSON conversion must be implemented.
This is the case for array types, for example. There exists sample code for
[int[2] array](https://github.com/plainC/wondermacros/blob/master/wondermacros/objects/json/int_array_2.c).
That can be used for a property `VAR(public,foo,int,Array(2) JSON(int_array_2))`, for instance.
To implement JSON conversion for a type two functions must be provided. They are:

* `int json_<type name>_to_string(void* value, char* buffer, size_t size)`
* `int json_<type name>_from_string(const char* buffer, const char** endptr, void* value)`

`to_string` returns the number of characters written to buffer, or -1 on error. The `value` argument points
to the storage location of the property.

`from_string` returns 0 if the conversion is successful, 1 otherwise. The `value` argument points to the
storage location of the property. `endptr` should point to the first character that was not used.

### Signals

It is possible to implement observer pattern using build-in signal mechanism
in the O-O framework. To add a signal into a class, use `SIGNAL` macro in the
class file. For instance, to add signal `on_move` to `Point` class we could define it
like this:

```
#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,public,void,draw)                            \
    SIGNAL(on_move, int steps)                                \
                       \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
```
Now to connect a signal into instance of `Point` we can use `W_CONNECT` macro.
For instance, if we have an object `struct Point*` created in `p`, we
can attach a callback `my_cb` to signal `on_move` using the following code:
```
W_OBJECT_SIGNAL_TYPE* handle;

W_CONNECT(p,on_move,my_cb, handle);
```
The `handle` is needed to deattach the callback later. To unbind a callback,
just use `W_DISCONNECT(handle)`. To unbind all bindings to a signal at once,
use `W_DISCONNECT_ALL(object,signal)`.

In the class implementation, we can emit signals using `W_EMIT`. For example,
`W_EMIT(self,on_move,steps);` emits `on_move` signal with an argument `steps`.
If the signal does not take any arguments, use `W_EMIT_VOID`.

Finally, a callback can be implemented like this.

```
void
my_cb(struct Point* self, int steps)
{
    printf(" Moved: %d steps\n",steps);
}
```

The first argument is always the object itself.

### Restrictions

Do not use the following names when specifing the name of a property. They are reserved for other purposes.
* the name of the class (e.g. `VAR(read,int,Point)` is not valid in `Point` class
* `klass`
* all reserved words in the C language

Do not use the following names when specifing the name of a method. They are reserved for other purposes.
* `meta`
* `free`
* `to_json`
* `from_json`
* all reserved words in the C language

### Writting other declarations directly to the class file

To specify simple types and other declarations directly in the class file,
it is possible to use `TO_HEADER` macro. Just define that macro in the class
file and the content is expanded with `<wondermacros/objects/x/class_declare.h>`.
For example, function callback types, simple enums and type definitions can
be specified in the same place with the class.

It is also possible to add file inclusions in the class file. Define `INCLUDE_0`
...`INCLUDE_3` macros in the class. Each one of them is able to include one
file, e.g. `#define INCLUDE_0 <stdio.h>`.

### wobject Tool

`wobject` tool helps to skip all steps in maintaining boilerplate code needed
by the O-O framework. It takes a simple class specification and builds the
necessary headers and initial C file, if it does not exist already. The format
is the following:

```
// Define a class ClassName which inherits SuperClassName. It uses Other class
uses Other
class ClassName : SuperClassName
  construct                       // we have a constructor
  finalize                        // we have a destructor
  public int x                    // defines a public property
  private int y                   // defines a private property
  public int foo()                // defines a method which does not take arguments
  public int goo(struct Other* o) // defines a method with an argument
  override superfunc              // we will override superfunc
```


### Source code and other examples

The source code of the previous example can be found 
[here](https://github.com/plainC/wondermacros/tree/master/examples/objects/point). There is 
[another example](https://github.com/plainC/wondermacros/tree/master/examples/objects/html) which
implements a simple web content generation classes (HTML elements, HTML attributes, strings and simple string templates).

See also [Web Elements](https://github.com/plainC/web_elements).

```C
int main()
{
    int v=42;
    double e=2.744;
    double* prices = NULL;
    int has_prices = 1;

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

