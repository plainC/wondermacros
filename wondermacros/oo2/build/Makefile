CFLAGS=-g -I .. -I .
CLASSESS=\
	Variant \
	Writer \
	Reader \
	Object \
	Symbol \
	SpecialForm \
	Quote \
	PrimFunc \
	Lisp \
	Number \
	Int \
	Float \
	Ratio \
	True \
	Character \
	Nil \
	_Class \
	WhiteSpace \
	Cons \
	EvalContext \
	BinOp \
	String \
	StringRef \
	Test \

OBJS = $(patsubst %,%.o,$(CLASSESS))
all : $(OBJS)
	ar rc libcore.a $(OBJS)
	ranlib libcore.a
Variant.o: Variant.c
	$(CC) $(CFLAGS) -c Variant.c
Writer.o: Writer.c
	$(CC) $(CFLAGS) -c Writer.c
Reader.o: Reader.c
	$(CC) $(CFLAGS) -c Reader.c
Object.o: Object.c
	$(CC) $(CFLAGS) -c Object.c
Symbol.o: Symbol.c
	$(CC) $(CFLAGS) -c Symbol.c
SpecialForm.o: SpecialForm.c
	$(CC) $(CFLAGS) -c SpecialForm.c
Quote.o: Quote.c
	$(CC) $(CFLAGS) -c Quote.c
PrimFunc.o: PrimFunc.c
	$(CC) $(CFLAGS) -c PrimFunc.c
Lisp.o: Lisp.c
	$(CC) $(CFLAGS) -c Lisp.c
Number.o: Number.c
	$(CC) $(CFLAGS) -c Number.c
Int.o: Int.c
	$(CC) $(CFLAGS) -c Int.c
Float.o: Float.c
	$(CC) $(CFLAGS) -c Float.c
Ratio.o: Ratio.c
	$(CC) $(CFLAGS) -c Ratio.c
True.o: True.c
	$(CC) $(CFLAGS) -c True.c
Character.o: Character.c
	$(CC) $(CFLAGS) -c Character.c
Nil.o: Nil.c
	$(CC) $(CFLAGS) -c Nil.c
_Class.o: _Class.c
	$(CC) $(CFLAGS) -c _Class.c
WhiteSpace.o: WhiteSpace.c
	$(CC) $(CFLAGS) -c WhiteSpace.c
Cons.o: Cons.c
	$(CC) $(CFLAGS) -c Cons.c
EvalContext.o: EvalContext.c
	$(CC) $(CFLAGS) -c EvalContext.c
BinOp.o: BinOp.c
	$(CC) $(CFLAGS) -c BinOp.c
String.o: String.c
	$(CC) $(CFLAGS) -c String.c
StringRef.o: StringRef.c
	$(CC) $(CFLAGS) -c StringRef.c
Test.o: Test.c
	$(CC) $(CFLAGS) -c Test.c

clean:
	rm -f $(OBJS)
