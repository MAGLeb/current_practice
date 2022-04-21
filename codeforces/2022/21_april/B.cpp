#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    int val;
    int res = -1;
    map<int, int> counter;
    cin >> k;
    while (k--) {
      cin >> val;
      if(counter.count(val)) {
        counter[val]++;
      } else {
        counter[val] = 1;
      }
      if(res == -1 && counter[val] == 3) {
        res = val;
      }
    }
    cout << res << endl;
  }
}