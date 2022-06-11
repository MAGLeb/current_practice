#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int l, k;
    cin >> l >> k;
    vector<int> v(l);

    for (int i = 0; i < l; i++)
      cin >> v[i];

    sort(rbegin(v), rend(v));

    for (int i = 1; i < l; i++)
      v[i] += v[i - 1];

    while(k--) {
      int q;
      cin >> q;
      auto it = lower_bound(begin(v), end(v), q);
      if (it == end(v))
        cout << "-1" << endl;
      else
        cout << it - begin(v) + 1 << endl;
    }


  }
}