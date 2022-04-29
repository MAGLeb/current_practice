#include <bits/stdc++.h>

using namespace std;

uint64_t find_path(int n, map<int, int> &mapper) {
  vector<int> inter;
  int k = n;
  while (n != 1) {
    if (n < k) {
      break;
    }
    inter.push_back(n);
    if (n % 2 == 0)
      n = n / 2;
    else
      n = 3 * n + 1;
  }

  int ans = inter.size() + mapper.at(n);

  for (auto val : inter) {
    mapper[val] = ans--;
  }

  return inter.size() + mapper.at(n);
}

int main() {
  map<int, int> result({make_pair(1, 1)});
  int answer = 0;
  int res = 0;

  for (int i = 2; i < 14; i++) {
    int new_answer = find_path(i, result);
    if (new_answer > answer)
      res = i;
    answer = max(answer, new_answer);
  }

  cout << res;
}