// Author: tim@normsoft.com (Tim Norman)

#include <iostream>

#include "dis/Disassembler.h"
#include "vc4/InstructionSet.h"
#include "vc4/test.h"

int main(int argc, char **argv) {
  Disassembler disassembler;
  disassembler.setTargetDisassemblable(new VC4::InstructionSet());

  int succeeded = 0;
  int failed = 0;
  VC4::Test(disassembler, &succeeded, &failed);

  std::cout << succeeded << " TESTS SUCCEEDED, " << failed << " TESTS FAILED" << std::endl;
}
