// 48-bit scalar instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _vc4_Scalar48Instructions_h_included_
#define _vc4_Scalar48Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Scalar48Instructions : public InstructionGroup {
  public:
    Scalar48Instructions();

    virtual int match(const unsigned char *in, size_t len);
  };

}

#endif
