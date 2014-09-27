// Author: tim@normsoft.com (Tim Norman)

#include <sstream>

#include "../dis/Disassembler.h"
#include "Registers.h"
#include "test.h"

namespace VC4 {

struct TestHarness {
 public:
  int succeeded;
  int failed;

  TestHarness() : succeeded(0), failed(0) { }

  void assertAlways(const std::string &msg) {
    std::cerr << "TEST FAILED: " << msg << std::endl;
    ++failed;
  }

  void assertTrue(bool condition, const std::string &msg) {
    if (!condition)
      assertAlways(msg);
    else
      ++succeeded;
  }

  template <typename T>
  void assertEquals(T v1, T v2, const std::string &msg) {
    assertTrue(v1 == v2, msg);
  }
};

static void trim_left(std::string &s) {
  while (s.length() > 0 && std::isspace(*(s.begin()))) {
    s.erase(s.begin(), s.begin() + 1);
  }
}

static void trim_right(std::string &s) {
  while (s.length() > 0 && std::isspace(*(s.end() - 1))) {
    s.erase(s.end() - 1, s.end());
  }
}

static void test_instr(Disassembler &disassembler, const char *inBuf, size_t len, const std::string &expectedOpCode, TestHarness &harness) {
  std::ostringstream out;
  std::istringstream in(std::string(inBuf, len));

  try {
    disassembler.disassemble(&in, &out);
  } catch (...) {
    harness.assertAlways(expectedOpCode);
    return;
  }

  std::string outString = out.str();

  trim_left(outString);
  trim_right(outString);
  harness.assertTrue(outString == expectedOpCode, expectedOpCode);
}

static void test_16bit_instr(Disassembler &disassembler, TestHarness &harness) {
  test_instr(disassembler, "\x00\x00\x00\x00", 4, "bkpt", harness);
  test_instr(disassembler, "\x01\x00\x00\x00", 4, "nop", harness);
  test_instr(disassembler, "\x02\x00\x00\x00", 4, "sleep", harness);
  test_instr(disassembler, "\x03\x00\x00\x00", 4, "user", harness);
  test_instr(disassembler, "\x04\x00\x00\x00", 4, "ei", harness);
  test_instr(disassembler, "\x05\x00\x00\x00", 4, "di", harness);
  test_instr(disassembler, "\x06\x00\x00\x00", 4, "cbclr", harness);
  test_instr(disassembler, "\x07\x00\x00\x00", 4, "cbinc", harness);
  test_instr(disassembler, "\x08\x00\x00\x00", 4, "cbchg", harness);
  test_instr(disassembler, "\x09\x00\x00\x00", 4, "cbdec", harness);
  test_instr(disassembler, "\x0a\x00\x00\x00", 4, "rti", harness);
}

static void test_registers(TestHarness &harness) {
  harness.assertEquals(Register::decode(0), std::string("r0"), "r0");
  harness.assertEquals(Register::decode(1), std::string("r1"), "r1");
  harness.assertEquals(Register::decode(2), std::string("r2"), "r2");
  harness.assertEquals(Register::decode(3), std::string("r3"), "r3");
  harness.assertEquals(Register::decode(4), std::string("r4"), "r4");
  harness.assertEquals(Register::decode(5), std::string("r5"), "r5");
  harness.assertEquals(Register::decode(6), std::string("r6"), "r6");
  harness.assertEquals(Register::decode(7), std::string("r7"), "r7");
  harness.assertEquals(Register::decode(8), std::string("r8"), "r8");
  harness.assertEquals(Register::decode(9), std::string("r9"), "r9");
  harness.assertEquals(Register::decode(10), std::string("r10"), "r10");
  harness.assertEquals(Register::decode(11), std::string("r11"), "r11");
  harness.assertEquals(Register::decode(12), std::string("r12"), "r12");
  harness.assertEquals(Register::decode(13), std::string("r13"), "r13");
  harness.assertEquals(Register::decode(14), std::string("r14"), "r14");
  harness.assertEquals(Register::decode(15), std::string("r15"), "r15");
  harness.assertEquals(Register::decode(16), std::string("r16"), "r16");
  harness.assertEquals(Register::decode(17), std::string("r17"), "r17");
  harness.assertEquals(Register::decode(18), std::string("r18"), "r18");
  harness.assertEquals(Register::decode(19), std::string("r19"), "r19");
  harness.assertEquals(Register::decode(20), std::string("r20"), "r20");
  harness.assertEquals(Register::decode(21), std::string("r21"), "r21");
  harness.assertEquals(Register::decode(22), std::string("r22"), "r22");
  harness.assertEquals(Register::decode(23), std::string("r23"), "r23");
  harness.assertEquals(Register::decode(24), std::string("r24"), "r24");
  harness.assertEquals(Register::decode(25), std::string("sp"), "sp");
  harness.assertEquals(Register::decode(26), std::string("lr"), "lr");
  harness.assertEquals(Register::decode(27), std::string("r27"), "r27");
  harness.assertEquals(Register::decode(28), std::string("r28"), "r28");
  harness.assertEquals(Register::decode(29), std::string("r29"), "r29");
  harness.assertEquals(Register::decode(30), std::string("sr"), "sr");
  harness.assertEquals(Register::decode(31), std::string("pc"), "pc");
}

void Test(Disassembler &disassembler, int *succeeded, int *failed) {
  TestHarness harness;
  test_registers(harness);
  test_16bit_instr(disassembler, harness);

  *succeeded = harness.succeeded;
  *failed = harness.failed;
}

}
