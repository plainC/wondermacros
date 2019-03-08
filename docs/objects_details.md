## Abstract classes

In order to define an abstract class, add `#define ABSTRACT` into the class
definition file. An abstract class does not need to implement
a constructor or a destructor, and `W_NEW` cannot create instances of that
class.

## Common superclass

Some object-oriented languages have a common superclass for all classes.
To get a common superclass just include `<wondermacros/objects/object.h>` in a
header of the project. By default, it will create a type called `struct Object`
which can be used as a superclass for all objects. If you prefer a lowercase
name, define `LOWERCASE_OBJECT` macro before the inclusion. If you prefer
`Object_t`, define `USE_T_TYPE_SUFFIX`. Both of them can be combined to get
`object_t`.

## Array properties and bit fields

It is possible to declare a fixed size array property using additional declaration with `Array(...)` macro.
For example, `VAR(public,int,items,Array(2))` declares one-dimensional array of two integers. Multi-dimensional
arrays are defined by adding dimensions to `Array` macro.

Sometimes we might want to save space, and declare properties with bit field length. For example,
`VAR(public,unsigned,tiny,Bits(3))` declares a property taking just three bits. This, however, saves space only
when multiple properties are delared sequentially and they fit into a word boundary. Note that to use bit fields
you must define `#define USE_BIT_FIELDS` in the class file, and JSON serialization cannot be used for that class.


### Writting other declarations directly to the class file

To specify simple types and other declarations directly in the class file,
it is possible to use `TO_HEADER` macro. Just define that macro in the class
file and the content is expanded with `<wondermacros/objects/x/class_declare.h>`.
For example, function callback types, simple enums and type definitions can
be specified in the same place with the class.

It is also possible to add file inclusions in the class file. Define `INCLUDE_0`
...`INCLUDE_3` macros in the class. Each one of them is able to include one
file, e.g. `#define INCLUDE_0 <stdio.h>`.

