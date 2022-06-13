#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  string s_binary;
  cin >> n >> k >> s_binary;

  int f = -1;
  int s = -1;
  int counter = 0;

  for (int i = 0; i < n; ++i) {
    if (s_binary[i] == '1') {
      ++counter;
      if (f == -1)
        f = i;
      s = i;
    }
  }

  if (f == -1 and s == -1)
    cout << 0 << endl;
  else if (f == s) {
    if (k >= n - 1 - f)
      cout << 1 << endl;
    else if (k >= f)
      cout << 10 << endl;
    else
      cout << 11 << endl;
  } else {
    int result = 0;
    if (k >= n - 1 - s) {
      k -= n - 1 - s;
      result += 1;
      --counter;
    }
    if (k >= f) {
      result += 10;
      --counter;
    }
    result += counter * 11;
    cout << result << endl;
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