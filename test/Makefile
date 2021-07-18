CFLAGS=-g -I . -I .. -I ../.. -Wall -Wextra -Wno-unused-value -Wno-unused-variable
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
LIBS =

all: $(PROGS)
%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

run: $(PROGS)
	./run.sh $(PROGS)


clean:
	rm -f *~ $(PROGS)

.PHONY: clean run
