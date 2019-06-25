#include "Nothing.h"

#ifndef WDEBUG_EXPAND
#include <stdio.h>
#include <math.h>
#endif

int main()
{
    Class* klass = (Class*) (&None)->klass;
    printf("%d\n", W_CALL(klass,is_super)(klass));
}

