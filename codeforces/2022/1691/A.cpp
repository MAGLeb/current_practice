#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;

  for (int i = 0; i < n; i++) {
    int inter;
    cin >> inter;
    if (inter % 2 == 0) {
      a++;
    } else {
      b++;
    }
  }

  cout << min(a, b) <<endl;
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