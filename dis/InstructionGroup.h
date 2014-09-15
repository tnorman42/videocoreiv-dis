// Logic group of instructions. This is used to create a tree of
// instruction groups so we can speed disassembly.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _InstructionGroup_h_included_
#define _InstructionGroup_h_included_

#include <istream>
#include <vector>
#include "Disassemblable.h"

class InstructionGroup : public Disassemblable {

  std::vector<Disassemblable *> disassemblables;

 public:
  InstructionGroup();
  virtual ~InstructionGroup();

  // Add a Disassemblable as part of this group.
  void addDisassemblable(Disassemblable *disassemblable);

  virtual bool match(std::istream *in);

  virtual void disassemble(std::istream *in, std::ostream *out);

};

#endif
