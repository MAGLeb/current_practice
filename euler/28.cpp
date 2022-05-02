#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t res = 1;
  int space = 2;
  int every = 0;
  int counter = 0;

  for(int i = 2; i < 1001 * 1001 + 1; i++) {
    every++;
    if (every == space) {
      res += i;
      every = 0;
      counter++;
    }
    if (counter == 4) {
      space += 2;
      counter = 0;
    }

  }
  cout << res << endl;
}