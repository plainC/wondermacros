SOURCES=\
	Test.c \

all: $(SOURCES)
	rm -rf build test
	./wobject.py core.wobject
	cd build && make
	gcc -I . -I build main.c simple_types.c -o test build/libcore.a


clean:
	rm -rf build test
