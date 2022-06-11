#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x = max(0, x - a);
    y = max(0, y - b);
    if (x + y > c)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}