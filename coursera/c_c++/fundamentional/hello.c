#include <math.h>
#include <stdio.h>
int main(void) {
  for (float i = 0; i < 1; i = i + 0.01) {
    printf("SIN of val %lf: %lf", i, sin(i));
    printf(" and COS: %lf\n", cos(i));
  }
    return 0;
}