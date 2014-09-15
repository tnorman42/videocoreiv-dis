// Author: tim@normsoft.com (Tim Norman)

#include "Scalar32Instructions.h"

namespace VC4 {

Scalar32Instructions::Scalar32Instructions() {
  // TODO
}

bool Scalar32Instructions::match(std::istream *in) {
  unsigned char lsb = 0, msb = 0;
  in->read((char *)&lsb, 1);
  in->read((char *)&msb, 1);
  in->putback(msb);
  in->putback(lsb);

  return 0x80 == (msb & 0x80);
}

}
