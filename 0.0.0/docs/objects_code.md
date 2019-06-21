## How to expand the header file of a class

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
