#include <cstring>
#include "Disassembler.h"

Disassembler::Disassembler() : targetDisassemblable(NULL) {
}

Disassembler::~Disassembler() {
  delete targetDisassemblable;
}

void Disassembler::setTargetDisassemblable(Disassemblable *disassemblable) {
  if (targetDisassemblable != NULL) {
    delete targetDisassemblable;
  }
  targetDisassemblable = disassemblable;
}

void Disassembler::disassemble(std::istream *in, std::ostream *out) {
  static const size_t kMaxBufferBytes = 16;
  unsigned char buf[kMaxBufferBytes];
  size_t bufFill = 0;

  while (!in->eof()) {
    bufFill = fillBuffer(buf, bufFill, kMaxBufferBytes, in);
    int bytesRead = targetDisassemblable->disassemble(buf, bufFill, out);
    bufFill = removeBytesReadFromBuffer(buf, bufFill, bytesRead);
  }
}

size_t Disassembler::fillBuffer(unsigned char *buf, size_t bufFill, size_t maxSize, std::istream *in) {
  if (bufFill == maxSize) {
    return bufFill;
  }

  in->read((char *)&buf[bufFill], maxSize - bufFill);
  return bufFill + in->gcount();
}

size_t Disassembler::removeBytesReadFromBuffer(unsigned char *buf, size_t bufFill, int bytesRead) {
  if (bufFill != bytesRead) {
    memmove(buf, buf + bytesRead, bufFill - bytesRead);
  }
  return bufFill - bytesRead;
}
