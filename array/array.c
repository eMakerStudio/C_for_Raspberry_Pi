#include <stdio.h>
int main()
{
  /* Create an array with four elements and assign values. */
  float fourVector[4] = {1.0, 2.0, 0.5, 2.292};
  /* Print the number of elements in the array. */
  printf("There are %ld elements\n" , sizeof(fourVector)/sizeof(float));
  /* Print the fourth element. */
  printf("fourVector[3]=%f\n", fourVector[3]);
  /* Return the success to the operation system */
  return 0;
}



