// 16-bit scalar instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _vc4_Scalar16Instructions_h_included_
#define _vc4_Scalar16Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Scalar16Instructions : public InstructionGroup {
  public:
    Scalar16Instructions();

    virtual int match(const unsigned char *in, size_t len);
  };

}

#endif
