#include <bits/stdc++.h>

using namespace std;

uint64_t find_path(uint64_t n, map<int, uint64_t> &mapper) {
  vector<int> inter;
  uint64_t k = n;
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

  uint64_t ans = inter.size() + mapper.at(n);

  for (auto val : inter) {
    mapper[val] = ans--;
  }

  return inter.size() + mapper.at(n);
}

int main() {
  map<int, uint64_t> result({make_pair(1, 1)});
  uint64_t answer = 0;
  int res = 0;

  for (int i = 2; i < 1'000'000; i++) {
    uint64_t new_answer = find_path(i, result);
    if (new_answer > answer)
      res = i;
    answer = max(answer, new_answer);
  }

  cout << res;
}