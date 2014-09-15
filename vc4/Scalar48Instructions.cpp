// Author: tim@normsoft.com (Tim Norman)

#include "Scalar48Instructions.h"

namespace VC4 {

Scalar48Instructions::Scalar48Instructions() {
  // TODO
}

bool Scalar48Instructions::match(std::istream *in) {
  unsigned char lsb = 0, msb = 0;
  in->read((char *)&lsb, 1);
  in->read((char *)&msb, 1);
  in->putback(msb);
  in->putback(lsb);

  return 0xe0 == (msb & 0xe0);
}

}
