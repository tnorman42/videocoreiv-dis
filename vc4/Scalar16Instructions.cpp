// Author: tim@normsoft.com (Tim Norman)

#include "Scalar16Instructions.h"

namespace VC4 {

Scalar16Instructions::Scalar16Instructions() {
  // TODO
}

bool Scalar16Instructions::match(std::istream *in) {
  unsigned char lsb = 0, msb = 0;
  in->read((char *)&lsb, 1);
  in->read((char *)&msb, 1);
  in->putback(msb);
  in->putback(lsb);

  return 0 == (msb & 0x80);
}

}
