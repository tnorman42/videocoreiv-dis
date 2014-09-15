// Author: tim@normsoft.com (Tim Norman)

#include <sstream>

#include "../dis/Disassembler.h"
#include "test.h"

namespace VC4 {

static void trim_left(std::string &s) {
  while (s.length() > 0 && std::isspace(*(s.begin()))) {
    s.erase(s.begin(), s.begin() + 1);
  }
}

static void trim_right(std::string &s) {
  while (s.length() > 0 && std::isspace(*(s.end() - 1))) {
    s.erase(s.end() - 1, s.end());
  }
}

static void test(Disassembler &disassembler, const char *inBuf, size_t len, const std::string &expectedOpCode, int *succeeded, int *failed) {
  std::ostringstream out;
  std::istringstream in(std::string(inBuf, len));

  try {
    disassembler.disassemble(&in, &out);
  } catch (...) {
    std::cerr << "TEST FAILED: " << expectedOpCode << std::endl;
    (*failed)++;
    return;
  }

  std::string outString = out.str();

  trim_left(outString);
  trim_right(outString);
  if (outString == expectedOpCode) {
    (*succeeded)++;
  } else {
    std::cerr << "TEST FAILED: " << expectedOpCode << std::endl;
    (*failed)++;
  }
}

void Test(Disassembler &disassembler, int *succeeded, int *failed) {
  test(disassembler, "\x00\x00\x00\x00", 4, "bkpt", succeeded, failed);
}

}
