#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k, a, b;
  cin >> k >> a >> b;
  int a_mod = a % k;
  int a_div = a / k;
  int b_div = b / k;
  int b_mod = b % k;

  if (a_div and b_div)
    cout << a_div + b_div << endl;
  else if (a_div > 0 and a_mod == 0)
    cout << a_div << endl;
  else if (b_div > 0 and b_mod == 0)
    cout << b_div << endl;
  else
    cout << -1 << endl;

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

  solve();

  return 0;
}