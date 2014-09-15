BIN=videocoreiv-dis

OBJS= \
	main.o \
	dis/Disassembler.o \
	dis/InstructionGroup.o

$(BIN): $(OBJS)
	g++ -o $@ $<

clean:
	rm $(BIN)
	find . -name "*~" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
