# Stack options

Some macros support multiple types of stacks. Simplest stack is static
array which cannot grow but has a check for overflow. Dynamic stack grows
but uses heap (malloc/free). Dynamic alloca stack also grows and uses C
stack with alloca. It may not be available on some systems.

To choose a stack include the specific stack configuration before including
the macro definitions.

## Static array stack

Use the following include to use static array stack.

```
#include <wondermacros/configs/stack/static_array.h>
```

This stack does not grow but has a check for stack overflow. In the case
of overflow, `W_RAISE` is run.

## Dynamic stack

Use the following include to use dynamic stack.

```
#include <wondermacros/configs/stack/dynamic_heap_array.h>
```

This stack grows and uses heap allocations (malloc and free). In the case
when allocation fails `W_RAISE` is run.

## Dynamic alloca

Use the following include to use dynamic alloca stack.

```
#include <wondermacros/configs/stack/dynamic_alloca.h>
```

This stack grows and uses C stack with alloca. There is no check for alloca
to fail but system most likely segmentation faults. Typically this is not
an issue for most programs. Note that alloca may not be available on some
systems.
