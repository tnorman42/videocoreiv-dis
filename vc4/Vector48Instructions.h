// 48-bit vector instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _Vector48Instructions_h_included_
#define _Vector48Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Vector48Instructions : public InstructionGroup {
  public:
    Vector48Instructions();

    virtual bool match(std::istream *in);
  };

}

#endif
