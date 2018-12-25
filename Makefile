DESTDIR=/usr/include

all:
	cd examples && make all

install:
	cp -r wondermacros $(DESTDIR)

clean:
	cd examples && make clean
