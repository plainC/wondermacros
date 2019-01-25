CFLAGS =            \
	-I .        \
	-I ../../.. \
        -g          \


SRCS =                    \
	html.c           \
	html_elem.c   \
	html_attr.c \

CLASSES = \
	html_class.h \
	html_elem_class.h \
	html_attr_class.h \


OBJS = $(patsubst %.c,%.o,$(SRCS))

test: $(SRCS) $(OBJS) test.c $(CLASSES)
	cc $(CFLAGS) -o test test.c $(OBJS)

$(OBJS): $(SRCS) $(CLASSES)
	cc -c $(CFLAGS) $^

clean:
	rm -f test $(OBJS) *.gch
