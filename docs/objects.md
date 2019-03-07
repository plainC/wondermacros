# Object-Oriented Programming in C

Wondermacros provides an object-oriented programming framework based on macros.
Define a class:
```
#define CLASS Point
#define BUILD_JSON

#define Point__define                            \
    METHOD(Point,public,int,move_up,(int steps)) \
    METHOD(Point,public,void,draw)               \
                                                 \
    VAR(read,int,x,JSON(json_int))               \
    VAR(read,int,y,JSON(json_int))               \
    /**/
```
Implement the class:
```
METHOD(Point,public,int,move_up,(int steps))
{
    if (self->y - steps < 0) {
        printf("Hits the wall\n");
        self->y = 0;
        return 1;
    }

    self->y -= steps;
    return 0;
}

METHOD(Point,public,void,draw)
{
    printf("point at %d,%d\n", self->x, self->y);
}
```
And use it:
```
int main()
{
    Point_t* p =  W_NEW(Point, .x=1, .y=7);
    W_CALL(p,move_up)(2);
    W_CALL_VOID(p,draw);

    char buffer[256];
    if (W_CALL(p,to_json)(buffer,256) < 0)
        printf("Error\n");
    else
        printf("%s\n", buffer);
           
    W_CALL_VOID(p,free);
}
```
### [Introduction](https://github.com/plainC/wondermacros/blob/master/docs/objects_introduction.md)
### [Defining a Class](https://github.com/plainC/wondermacros/blob/master/docs/objects_class.md)
&nbsp;&nbsp;#### [How to Define a Class](objects_class.md)
&nbsp;&nbsp;#### [How to Inherit a Class](objects_class.md)
### [Expanding to Source Code](https://github.com/plainC/wondermacros/blob/master/docs/objects_code.md)
### [Implementing a class](https://github.com/plainC/wondermacros/blob/master/docs/objects_implementing.md)
### [Objects API](https://github.com/plainC/wondermacros/blob/master/docs/objects_api.md)
&nbsp;&nbsp;#### [W_NEW: How to create an object](objects_api.md)
&nbsp;&nbsp;#### [W_CALL: How to call methods of an object](objects_api.md)
### [Details of Class Definitions](https://github.com/plainC/wondermacros/blob/master/docs/objects_details.md)
&nbsp;&nbsp;#### [Abstract Classes](objects_details.md)
&nbsp;&nbsp;#### [Common Superclass](objects_details.md)
&nbsp;&nbsp;#### [Array Properties and Bit Fields](objects_details.md)
&nbsp;&nbsp;#### [Writting Other Declarations Directly to the Class File](objects_details.md)
### [JSON Serialization and Marshalling](https://github.com/plainC/wondermacros/blob/master/docs/objects_json.md)
### [Signals](https://github.com/plainC/wondermacros/blob/master/docs/objects_signals.md)
### [wobject Tool: Erase all boilerplate code at once](https://github.com/plainC/wondermacros/blob/master/docs/objects_wobject.md)
### [Restrictions and Debugging](https://github.com/plainC/wondermacros/blob/master/docs/objects_restrictions.md)
### [Source Code and Examples](https://github.com/plainC/wondermacros/blob/master/docs/objects_examples.md)

