#include <stdio.h>
int main() {
  int c;
  /* Create a null FILE pointer */
  FILE *ptr = 0 ;
  /* List the files in a directory and listen */
  ptr = popen("ls ./" , "r");
  /* If the command fails return failure  */
  if(!ptr) return 1;
  /* Read each character */
  while((c = fgetc(ptr)) != EOF) {
    /* Print the characters */
    printf("%c" ,(char)c);
  }
  /* Close the pipe */
  pclose(ptr);
  return 0;
}



