SRCS = \
	point2d.c \
	point3d.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

CFLAGS = \
	-I ../../.. \
	-g \
	-Wall \
	-Wextra \
	-Wno-override-init \

test: $(OBJS) $(SRC) test.c
	gcc $(CFLAGS) -o test test.c $(OBJS)

%: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f test $(OBJS)
