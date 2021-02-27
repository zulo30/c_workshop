#include <stdio.h>             
#include <gmp.h>   
#include "./pi.h" 

int main (void)
{
  mpf_t pi_value;
  calculate_pi(pi_value);
  gmp_printf("Valor de pi  %.*Ff con %d digitos \n",11,pi_value,11);
  return 0;


}
