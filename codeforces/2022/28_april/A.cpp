#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string res = "NO";
    string s;
    char c;
    cin >> s >> c;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c && i % 2 == 0) {
        res = "YES";
        break;
      }
    }

    cout << res << endl;
  }
}