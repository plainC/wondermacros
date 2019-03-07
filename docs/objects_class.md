## How to define a class
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

## How to inherit a class

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

###### Prev: [Introduction](https://github.com/plainC/wondermacros/blob/master/docs/objects_introduction.md)
###### Next: [Expanding to Source Code](https://github.com/plainC/wondermacros/blob/master/docs/objects_code.md)
