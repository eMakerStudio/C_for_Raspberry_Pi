#include <stdio.h>
int main()
{
  /* Declare an int and assign it the value three. */
  int i = 3;
  /* Declare a float and asssign it the value three. */
  float f = 3;
  /* Divide i by two and assign the result to i. */
  i /= 2;
  /* Divide f by two and assign the result to f. */
  f /= 2.;
  /* Print the result */
  printf("int (3/2) = %d, float (3./2.) = %f\n",i,f);
  /* Return success to the OS. */
  return 0;
}


