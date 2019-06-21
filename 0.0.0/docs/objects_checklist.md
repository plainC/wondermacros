## Checklist

Debugging is the biggest issue when working with macros. Here is a checklist
of common issues if code does not compile.

### General issues
* If you are not using the default configuration, are the configuration
  macros included for all classes? Make sure the configuration is set up
  as the first thing in a the main header of the project.

### Class file: e.g. `Point_class.h`
* You have defined the class name, e.g. `#define CLASS Point`
* You have defined the class itself, e.g. `#define Point__define ...`
* If you inherit another class you have
  * Defined the superclass, e.g. `#define SUPER SuperOfPoint`
  * You have added the superclass definition to the class definition,
    e.g `SuperOfPoint__define` is in the first line in `Point__define`
* Every line in class defintion, e.g. `Point__define` ends with backslash
* Each method has the class name as the first argument
  e.g. `METHOD(Point,int,ping,(int arg1, int arg2))`
* Each method is set `public` or `private` in the second argument
* Each `METHOD` macro has four or five arguments, and, if the fifth argument
  is given (the argument list of the method) they are in parenthesis
* Each `VAR` macro has three or four arguments where the first argument is
  `public`, `private` or `read`

### Class implementation: e.g. `Point.c`

* Include the needed headers in the file first. Include also the header
  of the class `Point.h` and other class headers which are needed in the
  implementation of the class
* Each `METHOD` is excatly the same than in the class file. Also the name
  of the class must be repeated.
* The code implementing the class is written between inclusions of
  `<wondermacros/objects/x/class_start.h> and <wondermacros/objects/x/class_end.h>
* Before including `class_start` X-macro, you must include the class file
* If you have implemented a method but it gets the method of the superclass
  is always called instead, you have forgotten to override the method in
  the class definition file. Add e.g. `OVERRIDE(Point,a_method)` to the
  class file.
