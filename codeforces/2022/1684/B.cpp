#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << c + b + a << ' ' << c + b << ' ' << c << endl;
  }
}