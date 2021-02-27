/*=======Test Runner Used To Run Each Test Below=====*/
 #define RUN_TEST(TestFunc, TestLineNum)                                        \
   {                                                                            \
     Unity.CurrentTestName = #TestFunc;                                         \
     Unity.CurrentTestLineNumber = TestLineNum;                                 \
     Unity.NumberOfTests++;                                                     \
     if (TEST_PROTECT()) {                                                      \
       setUp();                                                                 \
       TestFunc();                                                              \
     }                                                                          \
     if (TEST_PROTECT()) {                                                      \
       tearDown();                                                              \
     }                                                                          \
     UnityConcludeTest();                                                       \
   }

 /*=======Automagically Detected Files To Include=====*/
 #include <gmp.h>

 #include "../../src/exercise_01/pi.h"
 #include "../vendor/unity.h"

 /*=======External Functions This Runner Calls=====*/
 extern void setUp(void);
 extern void tearDown(void);
 extern void test_calculate_pi_with_eleven_decimal(void);

 /*=======Test Reset Option=====*/
 void resetTest(void);
 void resetTest(void)
 {
   tearDown();
   setUp();
 }

 /*=======MAIN=====*/
 int main(void)
 {
   UnityBegin("test/exercises/test_exercise_01.c");
   RUN_TEST(test_calculate_pi_with_eleven_decimal, 14);

   return (UnityEnd());
 }

