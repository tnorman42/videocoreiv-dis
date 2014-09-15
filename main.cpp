// Author: tim@normsoft.com (Tim Norman)

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "dis/Disassembler.h"
#include "vc4/InstructionSet.h"

int main(int argc, char **argv) {
  std::istream *inputFile = NULL;
  if (argc > 1) {
    std::ifstream *file = new std::ifstream(argv[1], std::ios::binary);
    if (file->is_open()) {
      inputFile = file;
    }
  } else {
    inputFile = &std::cin;
  }

  if (!inputFile) {
    fprintf(stderr, "Couldn't open input file.\n");
    exit(1);
  }

  Disassembler disassembler;
  disassembler.setTargetDisassemblable(new VC4::InstructionSet());
  disassembler.disassemble(inputFile, &std::cout);
}
