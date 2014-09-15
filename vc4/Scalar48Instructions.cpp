// Author: tim@normsoft.com (Tim Norman)

#include "Scalar48Instructions.h"

namespace VC4 {

Scalar48Instructions::Scalar48Instructions() {
  // TODO
}

int Scalar48Instructions::match(const unsigned char *in, size_t len) {
  return len >= 6 && 0xe0 == (in[1] & 0xe0) ? 6 : 0;
}

}
