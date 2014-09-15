// 32-bit scalar instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _Scalar32Instructions_h_included_
#define _Scalar32Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Scalar32Instructions : public InstructionGroup {
  public:
    Scalar32Instructions();

    virtual bool match(std::istream *in);
  };

}

#endif
