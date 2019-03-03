#include "forward_declare.h"
#include "Aircraft.h"
#include "Aircraft_class.h"
#include <wondermacros/objects/x/class_start.h>

METHOD(Aircraft,public,void,land)
{
}

METHOD(Aircraft,public,void,fly)
{
}

/* Override: start */
METHOD(Aircraft,public,void,start)
{
}

/* Override: stop */
METHOD(Aircraft,public,void,stop)
{
}

/* Override: turn */
METHOD(Aircraft,public,void,turn,(float angle))
{
}

/* Override: add_speed */
METHOD(Aircraft,public,void,add_speed,(float increment))
{
}

#include <wondermacros/objects/x/class_end.h>
