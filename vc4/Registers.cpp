// Author: tim@normsoft.com (Tim Norman)

#include <stdio.h>
#include "Registers.h"

namespace VC4 {
namespace Register {

std::string decode(uint8_t encoded) {
  switch (encoded) {
    case 25:
      return "sp";
    case 26:
      return "lr";
    case 30:
      return "sr";
    case 31:
      return "pc";
    default:
      char buf[5];
      sprintf(buf, "r%d", (int)encoded);
      return buf;
  }
}

}
}
