#include <stdio.h>
int main()
{
  /* Assigning the approximate value of PI. */
  float f = 3.14159; 
  /* Add a very small number to it */
  f+=0.0000001;
  /* Print the value stored in f */
  printf("%f\n",f);
  /* Return success to the OS */
  return 0;
}
