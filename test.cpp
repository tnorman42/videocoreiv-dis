// Author: tim@normsoft.com (Tim Norman)

#include <iostream>

#include "dis/Disassembler.h"
#include "vc4/InstructionSet.h"
#include "vc4/test.h"

int main(int argc, char **argv) {
  Disassembler disassembler;
  disassembler.setTargetDisassemblable(new VC4::InstructionSet());

  VC4::Test(disassembler);

  std::cout << "TESTS COMPLETE" << std::endl;
}
