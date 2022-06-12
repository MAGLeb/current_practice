#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  set<int> v;

  while (n--) {
    int inter;
    cin >> inter;
    v.insert(inter);
  }

  vector<int> answer;
  for(int i = 1; ; ++i) {
    if(v.count(i) == 0) {
      k -= i;
      if(k < 0)
        break;
      answer.push_back(i);
    }
  }

  cout << answer.size() << endl;
  for(const auto& val : answer)
    cout << val << ' ';
  cout << endl;
  return;
}

void solve_() {
  int n, k;
  cin >> n >> k;
  vector<bool> v(3 * pow(10, 5), false);

  while(n--) {
    int inter;
    cin >> inter;
    v[inter] = true;
  }
  vector<int> answer;

  for(int i = 1; i < v.size(); ++i) {
    if(!v[i]) {
      k -= i;
      if(k >= 0)
        answer.push_back(i);
      else
        break;
    }
  }

  cout << answer.size() << endl;
  for(const auto& val : answer)
    cout << val << ' ';
  cout << endl;
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