// Author: tim@normsoft.com (Tim Norman)

#include <stdexcept>
#include "InstructionGroup.h"

InstructionGroup::InstructionGroup() {
}

InstructionGroup::~InstructionGroup() {
  for (std::vector<Disassemblable *>::iterator it = disassemblables.begin();
       it != disassemblables.end(); ++it) {
    delete *it;
  }
}

void InstructionGroup::addDisassemblable(Disassemblable *disassemblable) {
  disassemblables.push_back(disassemblable);
}

bool InstructionGroup::match(std::istream *in) {
  for (std::vector<Disassemblable *>::iterator it = disassemblables.begin();
       it != disassemblables.end(); ++it) {
    if ((*it)->match(in)) {
      return true;
    }
  }
  return false;
}

void InstructionGroup::disassemble(std::istream *in, std::ostream *out) {
  for (std::vector<Disassemblable *>::iterator it = disassemblables.begin();
       it != disassemblables.end(); ++it) {
    if ((*it)->match(in)) {
      (*it)->disassemble(in, out);
      return;
    }
  }

  throw std::invalid_argument("Cannot dissasemble input.");
}
