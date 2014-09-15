// Author: tim@normsoft.com (Tim Norman)

#include "Vector48Instructions.h"

namespace VC4 {

Vector48Instructions::Vector48Instructions() {
  // TODO
}

int Vector48Instructions::match(const unsigned char *in, size_t len) {
  return len >= 6 && 0xf0 == (in[1] & 0xf0) ? 6 : 0;
}

}
