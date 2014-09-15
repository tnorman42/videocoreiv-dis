#include "Disassembler.h"

Disassembler::Disassembler() : targetDisassemblable(NULL) {
}

Disassembler::~Disassembler() {
  delete targetDisassemblable;
}

void Disassembler::setTargetDisassemblable(Disassemblable *disassemblable) {
  if (targetDisassemblable != NULL) {
    delete targetDisassemblable;
  }
  targetDisassemblable = disassemblable;
}

void Disassembler::disassmeble(std::istream *in, std::ostream *out) {
  while (!in->eof()) {
    targetDisassemblable->disassemble(in, out);
  }
}
