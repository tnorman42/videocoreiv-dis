// Author: tim@normsoft.com (Tim Norman)

#include "Vector80Instructions.h"

namespace VC4 {

Vector80Instructions::Vector80Instructions() {
  // TODO
}

int Vector80Instructions::match(const unsigned char *in, size_t len) {
  return len >= 10 && 0xf8 == (in[1] & 0xf8) ? 10 : 0;
}

}
