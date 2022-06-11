#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    vector<int> v;
    while (k--) {
      int val;
      cin >> val;
      v.push_back(val);
    }

    int res = 0;
    int start = 0;
    int end = v.size() - 1;
    uint64_t f = 0;
    uint64_t s = 0;

    while (start <= end) {
      if(f <= s)
        f += v[start++];
      else
        s += v[end--];

      if(f == s) {
        res = start + v.size() - end - 1;
      }
    }
    cout << res << endl;
  }
}