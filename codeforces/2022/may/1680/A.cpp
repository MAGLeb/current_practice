#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b < c || d < a) {
      cout << a + c << endl;
    } else {
      cout << max(a, c) << endl;
    }
  }
}