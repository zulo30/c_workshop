// Include the test framework.
#include "../vendor/unity.h"            
#include <stdio.h>             
#include <gmp.h>    

// Include the header file with the declarations of the functions you create.
#include "../../src/exercise_01/pi.h"

void setUp(void) {}

// Runs after every test.
void tearDown(void) {}

// Defines a single test.
// the number must contain 3.14159265359
void test_calculate_pi_with_eleven_decimal(void)
{
  //arrage 
  double PI = 3.14159265359;

  mpf_t actual, expected;
  mpf_init_set_d(expected,PI);
  mpf_init(actual);
  // act 
  calculate_pi(actual);
  // assert
  gmp_printf("Valor estimado de pi  es %.*Ff y el valo real es %.*Ff con %d digitos.\n",11,actual,11,expected,11);
  int result = mpf_cmp(actual,expected);
  TEST_ASSERT_TRUE( result ==  0);
}
