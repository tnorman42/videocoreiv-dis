// Interface that represents something that can be disassembled.
//
// Author: tim@normsoft.com (Tim Norman)

#include <istream>

class Disassemblable {
 public:
  // Returns true if the data in the stream can be disassembled with
  // this object.
  virtual bool match(std::istream *in) = 0;

  // Disassemble one instruction from the in stream to the out stream.
  virtual void disassemble(std::istream *in, std::ostream *out) = 0;
};
