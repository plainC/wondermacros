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

