#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k, answer;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  if (k == 1) {
    answer = n / 2;
    if (n % 2 == 0)
      answer = answer - 1;

  } else {
    answer = 0;

    for(int i = 1; i < n - 1; ++i) {
      if(v[i] - v[i - 1] - v[i + 1] > 0)
        ++answer;
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