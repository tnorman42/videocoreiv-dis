BIN=videocoreiv-dis

MAINOBJ=main.o

DISOBJS= \
	dis/Disassembler.o \
	dis/InstructionGroup.o \
	vc4/InstructionSet.o \
	vc4/Registers.o \
	vc4/Scalar16Instructions.o \
	vc4/Scalar32Instructions.o \
	vc4/Scalar48Instructions.o \
	vc4/SimpleScalar16Instruction.o \
	vc4/Vector48Instructions.o \
	vc4/Vector80Instructions.o

TESTOBJS= \
	test.o \
	vc4/test.o

$(BIN): $(MAINOBJ) $(DISOBJS)
	g++ -o $@ $^

test: $(TESTOBJS) $(DISOBJS)
	g++ -o distest $^
	./distest

clean: rmtmp
	rm -f $(BIN) $(MAINOBJ) $(DISOBJS) $(TESTOBJS)
	rm -f distest

rmtmp:
	find . -name "*~" -exec rm {} \;
