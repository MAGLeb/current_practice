#include <bits/stdc++.h>

using namespace std;

int diff(const string &f, const string &s) {
  int res = 0;
  for (int i = 0; i < f.size(); i++)
    res += abs((int)f[i] - (int)s[i]);
  return res;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int k, l;
    cin >> k >> l;

    vector<string> v(k);
    for (int i = 0; i < k; i++)
      cin >> v[i];

    int mN = numeric_limits<int>::max();
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        int d = diff(v[i], v[j]);
        if (d < mN)
          mN = d;
      }
    }

    cout << mN << endl;
  }
}