#include <stdio.h>

#include "exercise_01/pi.h"

// main function
main(void){
long double pi_val = calculate_pi();
printf("%Le\n",pi_val);
}