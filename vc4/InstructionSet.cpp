// Author: tim@normsoft.com (Tim Norman)

#include "InstructionSet.h"
#include "Scalar16Instructions.h"
#include "Scalar32Instructions.h"
#include "Scalar48Instructions.h"
#include "Vector48Instructions.h"
#include "Vector80Instructions.h"

namespace VC4 {

InstructionSet::InstructionSet() {
  addDisassemblable(new Vector80Instructions());
  addDisassemblable(new Vector48Instructions());
  addDisassemblable(new Scalar48Instructions());
  addDisassemblable(new Scalar32Instructions());
  addDisassemblable(new Scalar16Instructions());
}

}
