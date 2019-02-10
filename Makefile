DESTDIR=/usr/include

all:
	cd examples && make all
	cd test && make all
	cd docs && make all

install:
	cp -r wondermacros $(DESTDIR)

clean:
	cd examples && make clean
	cd test && make clean
