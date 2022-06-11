#include <bits/stdc++.h>

using namespace std;

bool check_diff(const string &f, const string &s) {
  return f[0] == s[0] && f[1] != s[1] || f[0] != s[0] && f[1] == s[1];
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    uint64_t res = 0;
    int k;
    cin >> k;
    vector<string> array;
    map<string, uint64_t> mapper;

    while (k--) {
      string val;
      cin >> val;
      array.push_back(val);
    }

    for (int i = 0; i < array.size(); i++) {
      for (auto p : mapper) {
        if(check_diff(array[i], p.first)) {
          --mapper[p.first];
        }
      }
      if (mapper.count(array[i])) {
        res += mapper[array[i]];
        continue;
      }
      uint64_t counter = 0;
      for (int j = i + 1; j < array.size(); j++) {
        if (check_diff(array[i], array[j])) {
          counter += 1;
        }
      }
      res += counter;
      mapper[array[i]] = counter;
    }
    cout << res << endl;
  }
}