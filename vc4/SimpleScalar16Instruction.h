// A 16-bit scalar instruction that doesn't have any parameters.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _vc4_SimpleScalar16Instruction_h_included_
#define _vc4_SimpleScalar16Instruction_h_included_

#include <ostream>
#include <stdint.h>
#include <string>

#include "../dis/Disassemblable.h"

namespace VC4 {

  class SimpleScalar16Instruction : public Disassemblable {
    uint16_t compiledOpCode;
    std::string opCode;

  public:
    SimpleScalar16Instruction(uint16_t inCompiledOpCode, const std::string &inOpCode);

    virtual int match(const unsigned char *in, size_t len);
    virtual int disassemble(const unsigned char *in, size_t len, std::ostream *out);
  };

}

#endif
