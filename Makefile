BIN=videocoreiv-dis

OBJS= \
	main.o \
	dis/Disassembler.o \
	dis/InstructionGroup.o \
	vc4/InstructionSet.o \
	vc4/Scalar16Instructions.o \
	vc4/Scalar32Instructions.o \
	vc4/Scalar48Instructions.o \
	vc4/Vector48Instructions.o \
	vc4/Vector80Instructions.o

$(BIN): $(OBJS)
	g++ -o $@ $^

clean: rmtmp
	rm -f $(BIN)
	rm -f $(OBJS)

rmtmp:
	find . -name "*~" -exec rm {} \;
