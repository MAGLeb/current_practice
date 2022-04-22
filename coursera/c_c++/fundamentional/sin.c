#include <math.h>
#include <stdio.h>

/*
The program calculate sinus of any INT value based on architecture of your
computer and return value from 0 to 1 not included.

 22.04.22
 Gleb Maksimov
*/

int main(void) {
  double x, ret;
  printf("Enter x in range of 0-1 to calculate sin(x): ");
  scanf("%lf", &x);

  ret = sin(x);
  printf("The sine of %lf is %lf\n", x, ret);
  return 0;
}