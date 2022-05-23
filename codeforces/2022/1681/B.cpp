#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m, inter;
  cin >> m;
  vector<int> v(m);

  for (int i = 0; i < m; i++)
    cin >> v[i];

  cin >> m;
  int shift = 0;
  while (m--) {
    cin >> inter;
    shift += inter;
    shift = (int) (shift % v.size());
  }

  cout << v[shift] << endl;
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;

  while (n--) {
    solve();
  }

  return 0;
}