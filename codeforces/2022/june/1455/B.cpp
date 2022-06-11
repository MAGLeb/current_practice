#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x;
  cin >> x;

  int i = 1;
  int curr = 0;
  while(curr < x) {
    curr += i;
    ++i;
  }
  --i;

  if (curr - x == 1)
    cout << i + 1 << endl;
  else
    cout << i << endl;
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