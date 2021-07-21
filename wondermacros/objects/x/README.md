# X-macros for Object-oriented Type System

## Lower level includes

### class_struct.h

Expands the struct defining the class. This struct holds the meta-data of the class,
constructor, destructor, instance builder and the virtual function table.

### instance_struct.h

Expands the struct defining an instance of the class. This struct holds all properties
of an object and pointer to the class instance.

### class_instance.h

Expands the class instance. Fills in the meta-data and the virtual function table.

### new.h

Expands the object builder for the class.

### free.h

Expands the object finalizer for the class.

### dup.h

Expands the object copy function for the class.

### to_json.h

Expands the object to JSON and from JSON conversion functions for the class.

## Higher level includes

### forward_declare.h

Used to forward declare a class.

### class_declare.h

Used to declare a class.

### class_start.h

Used to start the class code.

### class_end.h

Used to end the class code.
