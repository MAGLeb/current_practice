#include <bits/stdc++.h>

using namespace std;

void solve() {
  int size;
  cin >> size;
  vector<pair<int, int>> v_1(size);
  vector<pair<int, int>> v_2(size);

  for (int i = 0; i < size; i++) {
    cin >> v_1[i].first;
    v_1[i].second = i;
  }
  for (int i = 0; i < size; i++) {
    cin >> v_2[i].first;
    v_2[i].second = i;
  }

  sort(begin(v_1), end(v_1));

  for()

  sort(begin(v_2), end(v_2));

  vector<pair<int, int>> result;
  bool answer = true;
  for (int i = 0; i < size - 1; i++) {
    if (v_2[i].second == v_1[i].second)
      continue;

    for (int j = i + 1; j < size; j++) {
      if (v_1[j].second == v_2[i].second && v_1[j].first == v_1[i].first) {
        swap(v_1[i], v_1[j]);
        result.push_back(make_pair(i+1, j+1));
        break;
      } else if (v_2[j].second == v_1[i].second && v_2[j].first == v_2[i].first) {
        swap(v_2[i], v_2[j]);
        result.push_back(make_pair(i+1, j+1));
        i--;
        break;
      }
    }
    if (v_2[i].second != v_1[i].second) {
      answer = false;
      break;
    }
  }

  cerr << "V_1:" << endl;
  for(auto p : v_1) {
    cerr << p.first << ' ' << p.second << " : ";
  }
  cerr << endl;

  cerr << "V_2:" << endl;
  for(auto p : v_2) {
    cerr << p.first << ' ' << p.second << " : ";
  }
  cerr << endl;

  if (answer && result.size() <= 10000) {
    cout << result.size() << endl;
    for (auto p : result)
      cout << p.first << ' ' << p.second << endl;
  } else
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

  int n;
  cin >> n;

  while (n--) {
    solve();
  }

  return 0;
}