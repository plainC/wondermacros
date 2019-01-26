CFLAGS =            \
	-I .        \
	-I ../../.. \
        -g          \


SRCS =                 \
	html.c         \
	html_elem.c    \
	html_attr.c    \
	dom_string.c   \
	dom_list.c     \
	css_elem.c     \
	css_selector.c \

CLASSES = $(patsubst %.c,%_class.h,$(SRCS))
OBJS = $(patsubst %.c,%.o,$(SRCS))

test: $(SRCS) $(OBJS) test.c $(CLASSES) html_api.h
	cc $(CFLAGS) -o test test.c $(OBJS)

$(OBJS): $(SRCS) $(CLASSES)
	cc -c $(CFLAGS) $^

clean:
	rm -f test $(OBJS) *.gch
