SOURCES=\
	Nothing.c \
	Point.c \
	Point3D.c \
	ITest.c \
	IWriter.c \
	StdoutWriter.c \
	String.c \
	String8.c \
	StringTemplate.c \
	main.c

core_classes: $(SOURCES)
	./wobject.py core.wobject
	gcc -g $(SOURCES)

clean:
	rm -f *__class.h *.o a.out

