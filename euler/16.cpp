#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v(500, 0);
  v[0] = 2;

  for (int i = 1; i < 1000; i++) {
    int rest = 0;
    int index = 0;
    while (index < 500) {
      int val = v[index] * 2 + rest;
      v[index] = val % 10;
      if (val > 9)
        rest = 1;
      else
        rest = 0;
      index++;
    }
  }
  uint64_t res = 0;
  for(auto val : v) {
    res += val;
    cout << val << ' ';
  }
  cout << endl;
  cout << res << endl;
}