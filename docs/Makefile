DOCS = \
	dynamic_array.md \
	meta.md \

all: $(DOCS)

dynamic_array.md: ../wondermacros/array/dynamic_array.h
	echo "## Dynamic Array" > dynamic_array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_array.h >> ../../docs/dynamic_array.md

meta.md:
	echo "## Meta-programming" > meta.md
	cd ../wondermacros/meta && ../../tools/api_tool.pl >> ../../docs/meta.md


clean:
	rm -f $(DOCS)
