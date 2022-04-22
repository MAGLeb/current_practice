#include <stdio.h>
int main(void) {
  float miles = 26, yards = 385;
  int kilometers;
  kilometers = 1.609 * (miles + yards / 1760.0);
  printf("\nA marathon is %d kilometers.\n", kilometers);
  int a = 3, b = 4, c = -2;
  printf("\nanswer: %d\n", a / b);
  return 0;
}