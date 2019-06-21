## Introduction

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

###### Next: [Defining a Class](https://github.com/plainC/wondermacros/blob/master/docs/objects_class.md)
