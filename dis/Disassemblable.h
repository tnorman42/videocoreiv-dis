// Interface that represents something that can be disassembled.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _Disassemblable_h_included_
#define _Disassemblable_h_included_

#include <istream>

class Disassemblable {
 public:
  // Returns the number of bytes for the opcode if the data in the
  // input can be disassembled with this object or 0 if not.
  virtual int match(const unsigned char *in, size_t len) = 0;

  // Disassemble one instruction from the input and return the
  // number of bytes consumed.
  virtual int disassemble(const unsigned char *in, size_t len, std::ostream *out) = 0;
};

#endif
