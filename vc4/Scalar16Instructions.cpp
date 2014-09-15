// Author: tim@normsoft.com (Tim Norman)

#include "Scalar16Instructions.h"
#include "SimpleScalar16Instruction.h"

namespace VC4 {

Scalar16Instructions::Scalar16Instructions() {
  addDisassemblable(new SimpleScalar16Instruction(0x0000, "bkpt"));
  // TODO
}

int Scalar16Instructions::match(const unsigned char *in, size_t len) {
  return len >= 2 && 0 == (in[1] & 0x80) ? 2 : 0;
}

}
