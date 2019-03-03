#include "vehicles.h"

int main()
{
    struct Vehicle* v1 = W_NEW(Car);

    W_CALL(v1,add_speed)(2500);
    W_CALL(v1,add_speed)(1500);
    W_CALL(v1,add_speed)(1500);
    W_CALL(v1,add_speed)(2500);
    W_CALL(v1,add_speed)(3500);
}
