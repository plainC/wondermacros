CFLAGS =            \
	-I .        \
	-I ../../.. \
        -g          \


SRCS =                 \
	model.c        \
                       \
	var_int.c      \
	var_double.c   \
	               \
	html.c         \
	html_elem.c    \
	html_attr.c    \
	dom_string.c   \
	dom_list.c     \
	js_elem.c      \
	css_elem.c     \
	css_selector.c \
	cond.c         \
	array.c        \
	tree.c         \

#	ptr_string.c   \
#	ptr_int.c      \
#	ptr_double.c   \

CLASSES = $(patsubst %.c,%_class.h,$(SRCS))
OBJS = $(patsubst %.c,%.o,$(SRCS))

test: $(SRCS) $(OBJS) test.c $(CLASSES) html_api.h
	cc $(CFLAGS) -o test test.c $(OBJS)

$(OBJS): $(SRCS) $(CLASSES)
	cc -c $(CFLAGS) $^

clean:
	rm -f test $(OBJS) *.gch
