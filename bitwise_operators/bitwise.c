#include <stdio.h>
int main() {
  int bit = 0, i = 1;
  while(i>0) {
    printf(" pow(2, %2d) = %11d\n" ,bit,i);
    i = i<<1;
    bit++;
  }
  return 0;
}


