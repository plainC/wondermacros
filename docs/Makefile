DOCS = \
	dynamic_array.md \

all: $(DOCS)

dynamic_array.md: ../wondermacros/array/dynamic_array.h
	echo "# Dynamic Array" > dynamic_array.md
	echo "## Reference" >> dynamic_array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_array.h >> ../../docs/dynamic_array.md

clean:
	rm -f $(DOCS)
