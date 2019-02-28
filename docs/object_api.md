## Object-Oriented Programming API
    
### W_NEW(T [,...])
#### Arguments
```C
T                    a class name
...                  values to be set (e.g. W_NEW(point, .x=1, .y=2))
```
#### Description
    Use W_NEW to create (and to initialize) an object.
    
### W_CALL(self,method)(...)
#### Arguments
```C
self                 an object (an instance of a class)
method               a method name to be called
...                  arguments for the methods
```
#### Description
    Use W_CALL to call a method of an object with arguments. The macro will expand self automatically as the first argument of the argument list in the method call.
    
### W_CALL_STATIC(klass,self,method)(...)
#### Arguments
```C
klass                a name of a class whose method is to be called
self                 an object (an instance of a class)
method               a method name to be called
...                  arguments for the methods
```
#### Description
    Use W_CALL_STATIC to call a method of a specified class for an object with arguments following.
    
### W_CALL_VOID(self,method)
#### Arguments
```C
self                 an object (an instance of a class)
method               a method name to be called
```
#### Description
    Use W_CALL_VOID to call a method of an object without any arguments.
    
### W_CALL_STATIC_VOID(self,method)
#### Arguments
```C
klass                a name of a class whose method is to be called
self                 an object (an instance of a class)
method               a method name to be called
```
#### Description
    Use W_CALL_STATIC_VOID to call a method of a specified class.
    
### W_CALL_CONSTRUCT(klass)
#### Arguments
```C
klass                class name
```
#### Description
    Use W_CALL_CONSTRUCT to call a constructor of a superclass by the name of the class.
    
### W_CALL_FINALIZE(klass)
#### Arguments
```C
klass                class name
```
#### Description
    Use W_CALL_FINALIZE to call a destructor of a superclass by the name of the class.
    
### W_CALL_ACONSTRUCT(klass)
#### Arguments
```C
klass                class name
```
#### Description
    Use W_CALL_ACONSTRUCT to call a constructor of an abstract superclass.
    
### W_CALL_AFINALIZE(klass)
#### Arguments
```C
klass                class name
```
#### Description
    Use W_CALL_AFINALIZE to call a destructor of an abstract superclass.
    
### W_CLASS(name)
#### Arguments
```C
name                 a class name
```
#### Description
    Use W_CLASS to access the class instance.
    
### W_OBJECT_IS(self,T)
#### Arguments
```C
self                 an object
T                    a class name
```
#### Description
    Use W_OBJECT_IS to test if an object is of a specific class.
    
### W_OBJECT_AS(self,T)
#### Arguments
```C
self                 an object
T                    a class name
```
#### Description
    Use W_OBJECT_AS to coerce an object to a specific class type.
    
### W_OBJECT_CLASS_NAME(self)
#### Description
    Use W_OBJECT_CLASS_NAME to get a const char pointer to the name of the class.
