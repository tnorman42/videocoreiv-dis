// Author: tim@normsoft.com (Tim Norman)

#include "Vector48Instructions.h"

namespace VC4 {

Vector48Instructions::Vector48Instructions() {
  // TODO
}

bool Vector48Instructions::match(std::istream *in) {
  unsigned char lsb = 0, msb = 0;
  in->read((char *)&lsb, 1);
  in->read((char *)&msb, 1);
  in->putback(msb);
  in->putback(lsb);

  return 0xf0 == (msb & 0xf0);
}

}
