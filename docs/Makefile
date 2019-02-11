DOCS =                   \
	array.md         \
	compiler.md      \
	char.md          \
	debug.md         \
	deque.md         \
	dynamic_array.md \
	dynamic_stack.md \
	hash_table.md    \
	dlist.md         \
	cslist.md        \
	slist.md         \
	math.md          \
	pp_char.md       \
	meta.md          \
	sorting.md       \
	string.md        \
	test.md          \
	tree.md          \

all: $(DOCS)

array.md: ../wondermacros/array/get_size.h
	echo "## Generic Array Macros" > array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl get_size.h >> ../../docs/array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl for_each.h >> ../../docs/array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl for_each_reversed.h >> ../../docs/array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl move_left.h >> ../../docs/array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl move_right.h >> ../../docs/array.md

dynamic_array.md: ../wondermacros/array/dynamic_array.h
	echo "## Dynamic Array" > dynamic_array.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_array.h >> ../../docs/dynamic_array.md

slist.md: ../wondermacros/list/slist.h
	echo "## Singly-Linked List" > slist.md
	cd ../wondermacros/list && ../../tools/api_tool.pl slist.h >> ../../docs/slist.md

dlist.md: ../wondermacros/list/dlist.h
	echo "## Doubly-Linked List" > dlist.md
	cd ../wondermacros/list && ../../tools/api_tool.pl dlist.h >> ../../docs/dlist.md

cslist.md: ../wondermacros/list/cslist.h
	echo "## Singly-Linked Circular List" > cslist.md
	cd ../wondermacros/list && ../../tools/api_tool.pl cslist.h >> ../../docs/cslist.md

tree.md: ../wondermacros/tree/for_each.h
	echo "## Trees" > tree.md
	cd ../wondermacros/tree && ../../tools/api_tool.pl >> ../../docs/tree.md

test.md: ../wondermacros/test/test.h
	echo "## Unit Testing" > test.md
	cat test_x.md >> test.md
	cd ../wondermacros/test && ../../tools/api_tool.pl >> ../../docs/test.md

deque.md: ../wondermacros/array/deque.h
	echo "## Deque" > deque.md
	cd ../wondermacros/array && ../../tools/api_tool.pl deque.h >> ../../docs/deque.md

dynamic_stack.md: ../wondermacros/array/dynamic_stack.h
	echo "## Dynamic Stack" > dynamic_stack.md
	cd ../wondermacros/array && ../../tools/api_tool.pl dynamic_stack.h >> ../../docs/dynamic_stack.md

hash_table.md: ../wondermacros/array/hash_table.h
	echo "## Hash Table" > hash_table.md
	cd ../wondermacros/array && ../../tools/api_tool.pl hash_table.h >> ../../docs/hash_table.md


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

pp_char.md:
	echo "## Pre-Processor Character and String Tools" > pp_char.md
	cd ../wondermacros/pp_char && ../../tools/api_tool.pl >> ../../docs/pp_char.md

sorting.md:
	echo "## Sorting" > sorting.md
	cd ../wondermacros/sorting && ../../tools/api_tool.pl >> ../../docs/sorting.md

string.md:
	echo "## String Handling" > string.md
	cd ../wondermacros/string && ../../tools/api_tool.pl >> ../../docs/string.md


clean:
	rm -f $(DOCS)
