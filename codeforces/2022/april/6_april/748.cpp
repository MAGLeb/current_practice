#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  char s;
  if(k % 2) {
    ++k;
    s = 'L';
  } else
    s = 'R';

  k /= 2;
  int r = k % m;
  if(r == 0) {
    r = m;
  }

  cout << (k - r) / m + 1 << ' ' << r << ' ' << s;
}