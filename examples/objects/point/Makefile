CFLAGS =            \
	-I ../../.. \
        -g          \


SRCS =                    \
	point.c           \
	colored_point.c   \
	colored_point3d.c \

CLASSES = \
	point_class.h \
	colored_point_class.h \


OBJS = $(patsubst %.c,%.o,$(SRCS))

test: $(SRCS) $(OBJS) test.c $(CLASSES)
	cc $(CFLAGS) -o test test.c $(OBJS)

$(OBJS): $(SRCS) $(CLASSES)
	cc -c $(CFLAGS) $^

clean:
	rm -f test $(OBJS)
