// Disassembler interface for disassemebling a specific architecture.
//
// Author: tim@normsoft.com (Tim Norman)

#include <iostream>
#include "Disassemblable.h"

class Disassembler {

  Disassemblable *targetDisassemblable;

 public:
  Disassembler();
  ~Disassembler();

  // Sets the Disassemblable to disassemble instructions.
  // This class gains ownership of the pointer and will delete it.
  void setTargetDisassemblable(Disassemblable *Disassemblable);

  // Disassemble the binary from the in stream and output opcodes in
  // ASCII to the out stream.
  void disassmeble(std::istream *in, std::ostream *out);

};
