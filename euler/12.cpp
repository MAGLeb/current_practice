#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int delimiters(const int &n) {
  int result = 0;
  int i = n;

  while(i > 0) {
    if(n % i == 0)
      ++result;
    --i;
  }

  return result;
}

int main() {
  int triangle = 1;
  int result = 1;
  int increment = 2;

  while(result < 10000) {
    triangle += increment;
    ++increment;
    result = delimiters(triangle);
  }
  cout << "triangle: " << triangle << " result: " << result << endl;
}