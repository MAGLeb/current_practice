#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int v[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      v[i][j] = c - '0';
    }
  }
  int answer = 0;
  for (int i = 0; i < (n + 1) / 2; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      int nowi = i; int nowj = j;
      int sum = v[nowi][nowj];
      int oldj = nowj;
      nowj = n - nowi - 1;
      nowi = oldj;
      sum += v[nowi][nowj];
      oldj = nowj;
      nowj = n - nowi - 1;
      nowi = oldj;
      sum += v[nowi][nowj];
      oldj = nowj;
      nowj = n - nowi - 1;
      nowi = oldj;
      sum += v[nowi][nowj];

      answer += min(sum, 4 - sum);
    }
  }
  cout << answer << endl;
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