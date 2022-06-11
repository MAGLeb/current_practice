#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    for (int i = 0; i < 6; i++) {
      if (i < 3)
        a += (int)s[i];
      else
        b += (int)s[i];
    }
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}