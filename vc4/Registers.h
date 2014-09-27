// VC4 register decoding
//
// Author: tim@normsoft.com (Tim Norman)

#ifndef _vc4_Registers_h_included_
#define _vc4_Registers_h_included_

#include <string>
#include <stdint.h>

namespace VC4 {
  namespace Register {

    // Decode the 4-bit or 5-bit version of a register into its mnemonic.
    std::string decode(uint8_t encoded);

  }
}

#endif
