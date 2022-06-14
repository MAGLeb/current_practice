#include <bits/stdc++.h>

using namespace std;

void solve() {
  map<int, int> m;
  int k;
  cin >> k;

  while (k--) {
    int inter;
    cin >> inter;
    ++m[inter];
  }

  int repeat = 0;
  int result = 0;
  for(const auto& p : m) {
    repeat += p.second - 1;
    ++result;
  }

  if(repeat % 2 == 1)
    --result;

  cout << result << endl;

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