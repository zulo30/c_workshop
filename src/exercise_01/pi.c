#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */

// Define the function itself.
void nilakantha (mpf_t pi_value, long int n)
{
   
   unsigned long int num_one = 2;
   unsigned long int num_two = 3;
   unsigned long int num_three = 4;

   mpf_init_set_d (pi_value, (double) 3.0);

   int NUMERATOR = 4;
   for (int i = 0; i < n;i++)
   {

      //  inicializo una variable term que representa el termino que se quiere 
      //  dividir o suma
      mpf_t term;
      mpf_t d;
      
       /* d = num_one * num_two * num_three */
      mpf_init_set_ui (d, num_one);
      mpf_mul_ui (d, d,  num_two);
      mpf_mul_ui (d, d,  num_three);

      // 4 / ( num_one * num_two * num_three)
      mpf_init_set_d (term, NUMERATOR); /* term = 4.0*/
     
      mpf_div (term, term, d); /* term = term / d */
     


      if(i % 2 == 0)
      {
         // gmp_printf("SUMA::   %.*Ff  +  %.*Ff  con %d digitos ",11,pi_value,11,term,11);
         mpf_add (pi_value, pi_value, term);
         // gmp_printf(" = %.*Ff \n",11,pi_value);

      
      } else {
         // gmp_printf("RESTA::   %.*Ff  -  %.*Ff  con %d digitos ",11,pi_value,11,term,11);
         mpf_sub (pi_value, pi_value, term);
         // gmp_printf(" = %.*Ff \n",11,pi_value);
      
      }
      num_one += (unsigned long int) 2;
      num_two += (unsigned long int) 2;
      num_three +=( unsigned long int) 2;
   }

   //gmp_printf("Valor de pi  %.*Ff con %d digitos \n",11,pi_value,11);
}

 
void calculate_pi (mpf_t result)
{
   nilakantha (result, 100000);
}

