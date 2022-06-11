#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int m, k;
    map<int, int> mapper;
    cin >> m >> k;

    for (int i = 0; i < m; i++) {
      int p;
      cin >> p;
      mapper[p]++;
    }

    int l = 0;
    int r = 0;
    pair<int, int> answer = make_pair(l, r);

    auto it = begin(mapper);
    while (it != end(mapper) ) {
      while (it->second < k && it != end(mapper))
        it++;

      l = it->first;
      while (it->second >= k) {
        r = it->first;
        it++;
        if(it == end(mapper) || it->first - r != 1)
          break;
      }

      if (r - l > answer.second - answer.first)
        answer = make_pair(l, r);
    }

    if(answer.second == 0 && answer.first == 0)
      cout << "-1";
    else
      cout << answer.first << ' ' << answer.second;
    cout << endl;
  }
}