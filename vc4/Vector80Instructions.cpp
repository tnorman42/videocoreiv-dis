// Author: tim@normsoft.com (Tim Norman)

#include "Vector80Instructions.h"

namespace VC4 {

Vector80Instructions::Vector80Instructions() {
  // TODO
}

bool Vector80Instructions::match(std::istream *in) {
  unsigned char lsb = 0, msb = 0;
  in->read((char *)&lsb, 1);
  in->read((char *)&msb, 1);
  in->putback(msb);
  in->putback(lsb);

  return 0xf8 == (msb & 0xf8);
}

}
