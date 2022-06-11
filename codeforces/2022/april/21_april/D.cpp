#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string res = "YES";
    char c;
    char prev = 'W';
    map<char, int> mapper({{'B', 0}, {'R', 0}});
    int k;
    cin >> k;

    while (k--) {
      cin >> c;

      if (c != 'W')
        mapper[c]++;
      else if (c != prev) {
        if (min(mapper['B'], mapper['R']) < 1)
          res = "NO";
        mapper = map<char, int>({{'B', 0}, {'R', 0}});
      }
      prev = c;
    }

    if (c != 'W' && min(mapper['B'], mapper['R']) < 1)
      res = "NO";
    cout << res << endl;
  }
}
