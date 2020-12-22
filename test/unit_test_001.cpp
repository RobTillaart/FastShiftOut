//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the FastShiftIn library
//          https://github.com/RobTillaart/FastShiftIn
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "FastShiftOut.h"

unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/


unittest(test_constructor)
{
  FastShiftOut FSO(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTOUT_LIB_VERSION);
  assertEqual(LSBFIRST, FSO.getBitOrder());

  FSO.setBitOrder(MSBFIRST);
  assertEqual(MSBFIRST, FSO.getBitOrder());
}


unittest(test_constructor_LSB)
{
  FastShiftOut FSO(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTOUT_LIB_VERSION);
  assertEqual(LSBFIRST, FSO.getBitOrder());

  FSO.setBitOrder(MSBFIRST);
  assertEqual(MSBFIRST, FSO.getBitOrder());
}


unittest(test_constructor_MSB)
{
  FastShiftOut FSO(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTOUT_LIB_VERSION);
  assertEqual(MSBFIRST, FSO.getBitOrder());
  
  FSO.setBitOrder(LSBFIRST);
  assertEqual(LSBFIRST, FSO.getBitOrder());
}


unittest(test_write)
{
  FastShiftIn FSI(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);

  assertEqual(1, FSI.write(0x42));
  assertEqual(1, FSI.writeLSBFIRST(0xAA));
  assertEqual(1, FSI.writeMSBFIRST(0x55));
}


unittest(test_print)
{
  FastShiftIn FSO(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);

  assertEqual(5, FSI.print(FASTSHIFTIN_LIB_VERSION));
  assertEqual(7, FSI.println(FASTSHIFTIN_LIB_VERSION));
}



unittest_main()

// --------
