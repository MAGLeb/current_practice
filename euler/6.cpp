#include <iostream>

using namespace std;

int main() {
  unsigned long long result;

  for(int i = 1; i <= 100; ++i) {
    for(int j = i + 1; j <= 100; ++j) {
      cout << i << " " << j << endl;
      result += 2 * i * j;
    }
  }

  cout << result << endl;

}