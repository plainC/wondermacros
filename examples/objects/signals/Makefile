CFLAGS =            \
	-I ../../.. \
        -g          \


SRCS =                    \
	point.c           \

CLASSES = \
	point_class.h \


OBJS = $(patsubst %.c,%.o,$(SRCS))

all: test

test: $(SRCS) $(OBJS) test.c $(CLASSES)
	cc $(CFLAGS) -o test test.c $(OBJS)

$(OBJS): $(SRCS) $(CLASSES)
	cc -c $(CFLAGS) $^

uml.png: $(CLASSES)
	gcc -o uml.dot -I . -E -P uml.h
	dot -T png -o uml.png uml.dot

clean:
	rm -f test $(OBJS) *.gch uml.png uml.dot
