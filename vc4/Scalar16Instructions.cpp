// Author: tim@normsoft.com (Tim Norman)

#include "Scalar16Instructions.h"
#include "SimpleScalar16Instruction.h"

namespace VC4 {

Scalar16Instructions::Scalar16Instructions() {
  addDisassemblable(new SimpleScalar16Instruction(0x0000, "bkpt"));
  addDisassemblable(new SimpleScalar16Instruction(0x0001, "nop"));
  addDisassemblable(new SimpleScalar16Instruction(0x0002, "sleep"));
  addDisassemblable(new SimpleScalar16Instruction(0x0003, "user"));
  addDisassemblable(new SimpleScalar16Instruction(0x0004, "ei"));
  addDisassemblable(new SimpleScalar16Instruction(0x0005, "di"));
  addDisassemblable(new SimpleScalar16Instruction(0x0006, "cbclr"));
  addDisassemblable(new SimpleScalar16Instruction(0x0007, "cbinc"));
  addDisassemblable(new SimpleScalar16Instruction(0x0008, "cbchg"));
  addDisassemblable(new SimpleScalar16Instruction(0x0009, "cbdec"));
  addDisassemblable(new SimpleScalar16Instruction(0x000a, "rti"));
  // TODO
}

int Scalar16Instructions::match(const unsigned char *in, size_t len) {
  return len >= 2 && 0 == (in[1] & 0x80) ? 2 : 0;
}

}
