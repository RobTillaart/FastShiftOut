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


#include "FastShiftIn.h"

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
  FastShiftIn FSI(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);
  assertEqual(0, FSI.lastRead());
  assertEqual(LSBFIRST, FSI.getBitOrder());
  
  FSI.setBitOrder(MSBFIRST);
  assertEqual(MSBFIRST, FSI.getBitOrder());
}


unittest(test_constructor_LSB)
{
  FastShiftIn FSI(12, 13, LSBFIRST);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);
  assertEqual(0, FSI.lastRead());
  assertEqual(LSBFIRST, FSI.getBitOrder());
  
  FSI.setBitOrder(MSBFIRST);
  assertEqual(MSBFIRST, FSI.getBitOrder());
}


unittest(test_constructor_MSB)
{
  FastShiftIn FSI(12, 13, MSBFIRST);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);
  assertEqual(0, FSI.lastRead());
  assertEqual(MSBFIRST, FSI.getBitOrder());
  
  FSI.setBitOrder(LSBFIRST);
  assertEqual(LSBFIRST, FSI.getBitOrder());
}


unittest(test_read)
{
  FastShiftIn FSI(12, 13);

  fprintf(stderr, "VERSION:\t%s\n", FASTSHIFTIN_LIB_VERSION);

  assertEqual(255, FSI.read());
  assertEqual(255, FSI.readLSBFIRST());
  assertEqual(255, FSI.readMSBFIRST());
}



unittest_main()

// --------
