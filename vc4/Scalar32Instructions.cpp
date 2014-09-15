// Author: tim@normsoft.com (Tim Norman)

#include "Scalar32Instructions.h"

namespace VC4 {

Scalar32Instructions::Scalar32Instructions() {
  // TODO
}

int Scalar32Instructions::match(const unsigned char *in, size_t len) {
  return len >= 4 && 0x80 == (in[1] & 0x80) ? 4 : 0;
}

}
