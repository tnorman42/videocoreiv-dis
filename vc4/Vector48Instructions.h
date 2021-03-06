// 48-bit vector instructions.
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _vc4_Vector48Instructions_h_included_
#define _vc4_Vector48Instructions_h_included_

#include "../dis/InstructionGroup.h"

namespace VC4 {

  class Vector48Instructions : public InstructionGroup {
  public:
    Vector48Instructions();

    virtual int match(const unsigned char *in, size_t len);
  };

}

#endif
