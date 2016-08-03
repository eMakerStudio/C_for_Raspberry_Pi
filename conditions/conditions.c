#include <stdio.h>
int main()
{
  /* Start with twenty apples. */
  int apples = 20;
  /* Set the price */
  float cost, costPerApple = 0.20;
  /* Ask the costumer */
  printf("How many apples would you like to buy?\n");
  /* Read the number input from the keyboard */
  scanf("%d",&apples);
  /* Check, if there are enough apples left */
  if(apples > 20) {
   /* Apologise */
    printf("Sorry, we only have 20 apples left.\n");
  }
  else {
    /* Calculate the total cost. */ 
    cost = costPerApple*apples;
    /* Ask for the money */
    printf("That will be %.2f BatCoins please.\n" ,cost);
  }
  return 0;
}

