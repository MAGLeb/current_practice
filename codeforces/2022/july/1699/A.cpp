#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k;
  cin >> k;
  if(k % 2 == 1) {
    cout << -1 << endl;
  } else {
    cout << k / 2 << ' ' << k / 2 << ' ' << 0 << endl;
  }
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