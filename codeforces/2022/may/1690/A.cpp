#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k;
  cin >> k;

  cout << 2 << ' ' << k - 3 << ' ' << 1 << endl;
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