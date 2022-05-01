#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t n;
  cin >> n;
  vector<uint64_t> paths(n, 1);

  for(int i = 0; i < n; i++) {
    uint64_t summary = 0;
    for(auto &val : paths)
      summary += val;
    uint64_t inter = paths[0];
    paths[0] = summary;
    for(int j = 1; j < n; j++) {
      summary = paths[j];
      paths[j] = paths[j - 1] - inter;
      inter = summary;
    }
  }

  cout << paths[0] * 2 << endl;
}