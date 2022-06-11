#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int64_t l, r, a, b;
    cin >> l >> r >> a;
    b = max(l, r - ((r % a) + 1));
    cout << max(int64_t(r / a) + r % a, int64_t(b / a) + b % a) << endl;
  }
}