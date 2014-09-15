// 80-bit vector instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _Vector80Instructions_h_included_
#define _Vector80Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Vector80Instructions : public InstructionGroup {
  public:
    Vector80Instructions();

    virtual int match(const unsigned char *in, size_t len);
  };

}

#endif
