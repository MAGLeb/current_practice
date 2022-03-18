#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(const int &number) {
  int i = 2;

  while(i <= sqrt(number)) {
    if(number % i == 0) {
      return false;
    }
    ++i;
  }
  return true;
}

int main() {
  long result = 2;

  for(int i = 3; i < 2000000; i = i + 2) {
    if(is_prime(i)) {
      result += i;
    }
  }

  cout << result << endl;
}