#include <iostream>
#include <cmath>

using namespace std;

int main() {
  unsigned long long prime = 600851475143;

  for(int i = 2; i != prime; ++i) {
      while(prime % i == 0) {
        prime /= i;
        cout << i << endl;
      }
    }
    cout << prime << endl;
  }
