#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k;
  cin >> k;
  vector<int> v(k);

  for (int i = 0; i < k; ++i)
    cin >> v[i];

  if(k == 1) {
    cout << 1 << ' ' << 0 << endl;
    return;
  }

  int start = 0;
  int end = v.size() - 1;
  int alice = 0;
  int bob = 0;

  while (end - start > 1) {
    int mN = min(v[start], v[end]);
    v[start] -= mN;
    v[end] -= mN;

    if (v[start] == 0 and v[end] == 0) {
      if (end - start == 2) {
        alice += 2;
        ++bob;
      } else {
        ++alice;
        ++bob;
      }
      ++start;
      --end;
    } else {
      if (v[start] == 0) {
        ++alice;
        ++start;
      } else if (v[end] == 0) {
        ++bob;
        --end;
      }
    }
  }
  if (end - start == 1) {
    ++alice;
    ++bob;
  }
  cout << alice << ' ' << bob << endl;
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