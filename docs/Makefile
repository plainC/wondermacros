DOCS =                   \
	compiler.md      \
	char.md          \
	debug.md         \
	deque.md         \
	dynamic_array.md \
	dynamic_stack.md \
	math.md          \
	meta.md          \
	sorting.md       \

all: $(DOCS)

dynamic_array.md: ../wondermacros/array/dynamic_array.h
	echo "## Dynamic Array" > dynamic_array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_array.h >> ../../docs/dynamic_array.md

deque.md: ../wondermacros/array/deque.h
	echo "## Deque" > deque.md
	cd ../wondermacros/array && ../../tools/api_tool.pl deque.h >> ../../docs/deque.md

dynamic_stack.md: ../wondermacros/array/dynamic_stack.h
	echo "## Dynamic Stack" > dynamic_stack.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_stack.h >> ../../docs/dynamic_stack.md

char.md:
	echo "## Character and String Handling" > char.md
	cd ../wondermacros/pp_char && ../../tools/api_tool.pl >> ../../docs/char.md

compiler.md:
	echo "## Compiler Tools" > compiler.md
	cd ../wondermacros/compiler && ../../tools/api_tool.pl >> ../../docs/compiler.md

debug.md:
	echo "## Debugging" > debug.md
	cd ../wondermacros/debug && ../../tools/api_tool.pl >> ../../docs/debug.md

meta.md:
	echo "## Meta-programming" > meta.md
	cd ../wondermacros/meta && ../../tools/api_tool.pl >> ../../docs/meta.md
	cd ../wondermacros/pp && ../../tools/api_tool.pl >> ../../docs/meta.md

math.md:
	echo "## Mathematics" > math.md
	cd ../wondermacros/math && ../../tools/api_tool.pl >> ../../docs/math.md

sorting.md:
	echo "## Sorting" > sorting.md
	cd ../wondermacros/sorting && ../../tools/api_tool.pl >> ../../docs/sorting.md


clean:
	rm -f $(DOCS)
