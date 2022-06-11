#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;

    if (b % a == 0)
      cout << 1 << ' ' << b / a << endl;
    else
      cout << "0 0" << endl;
  }
}