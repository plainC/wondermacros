DOCS = \
	dynamic_array.md \
	math.md \
	meta.md \
	sorting.md \

all: $(DOCS)

dynamic_array.md: ../wondermacros/array/dynamic_array.h
	echo "## Dynamic Array" > dynamic_array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_array.h >> ../../docs/dynamic_array.md

meta.md:
	echo "## Meta-programming" > meta.md
	cd ../wondermacros/meta && ../../tools/api_tool.pl >> ../../docs/meta.md

math.md:
	echo "## Mathematics" > math.md
	cd ../wondermacros/math && ../../tools/api_tool.pl >> ../../docs/math.md

sorting.md:
	echo "## Sorting" > sorting.md
	cd ../wondermacros/sorting && ../../tools/api_tool.pl >> ../../docs/sorting.md


clean:
	rm -f $(DOCS)
