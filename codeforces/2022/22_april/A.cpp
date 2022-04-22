#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    string res = "YES";
    cin >> s;
    s += '#';
    int counter = 0;
    char prev = s[0];

    for (auto val : s) {
      if (val != prev) {
        if (counter < 2) {
          res = "NO";
          break;
        }
        counter = 1;
        prev = val;
      } else
        counter++;
    }
    cout << res << endl;
  }
}