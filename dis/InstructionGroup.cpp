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

int InstructionGroup::match(const unsigned char *in, size_t len) {
  int bytes;
  for (std::vector<Disassemblable *>::iterator it = disassemblables.begin();
       it != disassemblables.end(); ++it) {
    if (bytes = (*it)->match(in, len)) {
      return bytes;
    }
  }
  return 0;
}

int InstructionGroup::disassemble(const unsigned char *in, size_t len, std::ostream *out) {
  for (std::vector<Disassemblable *>::iterator it = disassemblables.begin();
       it != disassemblables.end(); ++it) {
    if ((*it)->match(in, len)) {
      return (*it)->disassemble(in, len, out);
    }
  }

  throw std::invalid_argument("Cannot dissasemble input.");
}
