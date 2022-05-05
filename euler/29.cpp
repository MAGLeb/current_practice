#include <bits/stdc++.h>

using namespace std;

pair<int, int> divisors(int n) {
  int divisor = 1;
  int res = 0;

  while(n != 1) {
    if(res != 0)
      return make_pair(0, 0);
    divisor++;
    while(n % divisor == 0) {
      res++;
      n /= divisor;
    }
  }
  return make_pair(divisor, res);
}

int main() {
  int n = 16;
  set<uint64_t> setter;
  map<int, set<int>> mapper;
  uint64_t res = 0;

  for(int i = 2; i <= n; i++) {
    auto p = divisors(i);

    if (p.first > 1) {
      auto s = mapper[p.first].size();
      for(int j = 2; j <= n; j++) {
        mapper[p.first].insert(j * p.second);
      }
      res += mapper[p.first].size() - s;
    }
    else {
      res += n - 1;
      mapper[i] = set<int>({});
      for(int j = 2; j <= n; j++)
        mapper[i].insert(j);
    }

    for(int j = 2; j <= n; j++)
      setter.insert(pow(i, j));
  }

  cout << setter.size() << ' ' << res << endl;
}