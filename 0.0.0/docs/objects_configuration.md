## Configurations for Objects and Classes in Wondermacros

### Main Level Configuration

These configurations are intended to be used for all classes in a project,
or, for a separate subsystem of a project. Define them in the main header
of the project to override the default configuration.

* LOWERCASE_OBJECT
* USE_T_TYPE_SUFFIX
* USE_GCC_EXTENSION_COUNTER

### Superclass Specific Configuration

These configurations should be kept the same within a class hierarchy. If
a superclass changes configuration, all subclasses should do the same as well.

* BUILD_JSON

### Class Specific Configuration

These configurations may be done separately for each class.

* ABSTRACT
* NO_CONSTRUCT
* NO_DESTRUCT
* TO_HEADER
* INCLUDE_<number>



