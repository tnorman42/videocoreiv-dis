// Author tim@normsoft.com (Tim Norman)

#include "SimpleScalar16Instruction.h"

namespace VC4 {

SimpleScalar16Instruction::SimpleScalar16Instruction(uint16_t inCompiledOpCode, const std::string &inOpCode)
  : compiledOpCode(inCompiledOpCode), opCode(inOpCode) {
}

int SimpleScalar16Instruction::match(const unsigned char *in, size_t len) {
  return (len >= 2 && in[0] == (compiledOpCode & 0xff) && in[1] == (compiledOpCode >> 8)) ? 2 : 0;
}

int SimpleScalar16Instruction::disassemble(const unsigned char *in, size_t len, std::ostream *out) {
  (*out) << opCode << std::endl;
  return 2;
}

}
