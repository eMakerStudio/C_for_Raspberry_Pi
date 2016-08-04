#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
  /* Create a sysinfo instance to hold the result. */
  struct sysinfo info;
  /* Get the system information */
  sysinfo(&info);
  printf("Memory used = %d\n" ,info.totalram - info.freeram);
  return 0;
}



