### Signals

It is possible to implement observer pattern using build-in signal mechanism
in the O-O framework. To add a signal into a class, use `SIGNAL` macro in the
class file. For instance, to add signal `on_move` to `Point` class we could define it
like this:

```
#define Point__define  \
    /* Inherits */     \
      /*none */        \
                       \
    METHOD(Point,public,int,move_up,(int steps))              \
    METHOD(Point,public,int,move_left,(int steps))            \
    METHOD(Point,public,void,draw)                            \
    SIGNAL(on_move, int steps)                                \
                       \
    VAR(read,int,x)    \
    VAR(read,int,y)    \
    /**/
```
Now to connect a signal into instance of `Point` we can use `W_CONNECT` macro.
For instance, if we have an object `struct Point*` created in `p`, we
can attach a callback `my_cb` to signal `on_move` using the following code:
```
W_OBJECT_SIGNAL_TYPE* handle;

W_CONNECT(p,on_move,my_cb, handle);
```
If you also want to bind a data pointer, use `W_CONNECT(p,on_move,(my_cb,data),handle`.
The extra paranthesis must be there.

The `handle` is needed to deattach the callback later. To unbind a callback,
just use `W_DISCONNECT(handle)`. To unbind all bindings to a signal at once,
use `W_DISCONNECT_ALL(object,signal)`.

In the class implementation, we can emit signals using `W_EMIT`. For example,
`W_EMIT(self,on_move,steps);` emits `on_move` signal with an argument `steps`.
If the signal does not take any arguments, use `W_EMIT_VOID`.

Finally, a callback can be implemented like this. Note that the first argument
is the object it self and the second argument is the data pointer which may
be bound with the callback with `W_CONNECT`.

```
void
my_cb(struct Point* self, void* data, int steps)
{
    printf(" Moved: %d steps\n",steps);
}
```

The first argument is always the object itself.


