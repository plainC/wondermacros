CFLAGS =            \
	-I ../../.. \
        -g          \

CLASSES = $(wildcard *_class.h)
SRCS    = $(patsubst %_class.h,%.c,$(CLASSES))
HEADERS = $(patsubst %.c,%.h,$(SRCS))
OBJS    = $(patsubst %.c,%.o,$(SRCS))

all: build_src

build_src: classes.wobject
	../../../tools/wobject classes.wobject
	echo "\nTo build type 'make test'"

test: $(OBJS) test.o Vehicle_class.h
	cc -o test test.o $(OBJS)

$(OBJS): $(SRCS) $(HEADERS) $(CLASSES) test.c
	cc -c $(CFLAGS) test.c $^

clean:
	rm -f test test.o $(OBJS) *.gch $(CLASSES) $(HEADERS) classes.h forward_declare.h
