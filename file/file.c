#include <stdio.h>
int main(int argc, char *argv[]) {
  int mask = 163;
  char c;
  FILE *inputFile = 0, *outputFile = 0;

  if(argc!=3) {
    printf(" Usage: %s <input file> <output file>\n" ,argv[0]);
    return 1;
  }

  inputFile = fopen(argv[1], "r");
  if(!inputFile) return 2;

  outputFile = fopen(argv[2], "w");
  if(!outputFile) return 3;

  c = fgetc(inputFile);
  while(c != EOF) {
    c ^= mask;
    fputc(c,outputFile);
    c = fgetc(inputFile);
  }

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
