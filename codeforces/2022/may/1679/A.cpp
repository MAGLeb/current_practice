#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    uint64_t m;
    cin >> m;

    if(m % 2 == 1 || m < 4)
      cout << -1 << endl;
    else {
      uint64_t x, y;
      x = m / 4;
      y = m / 6;

      if(m % 6 != 0)
        y++;

      cout << y << ' ' << x << endl;
    }
  }
}