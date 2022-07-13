#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  string yes = "yes"s;
  cin >> s;
  string answer = "YES"s;
  for(int i = 0; i < s.size(); ++i) {
    if(tolower(s[i]) != yes[i]) {
      answer = "NO"s;
      break;
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