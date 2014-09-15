// Disassembler interface for disassemebling a specific architecture.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _Disassembler_h_included_
#define _Disassembler_h_included_

#include <iostream>
#include "Disassemblable.h"

class Disassembler {

  Disassemblable *targetDisassemblable;

  size_t fillBuffer(unsigned char *buf, size_t bufFill, size_t maxSize, std::istream *in);
  size_t removeBytesReadFromBuffer(unsigned char *buf, size_t bufFill, int bytesRead);

 public:
  Disassembler();
  ~Disassembler();

  // Sets the Disassemblable to disassemble instructions.
  // This class gains ownership of the pointer and will delete it.
  void setTargetDisassemblable(Disassemblable *Disassemblable);

  // Disassemble the binary from the in stream and output opcodes in
  // ASCII to the out stream.
  void disassemble(std::istream *in, std::ostream *out);

};

#endif
