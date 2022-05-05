#include <bits/stdc++.h>

using namespace std;

template <typename Iterator>
int recursion(Iterator it, int curr, Iterator end) {
  if(curr > 200)
    return 0;
  if(curr == 200)
    return 1;
  if(it == end)
    return 0;
  return recursion(it, curr + *it, end) + recursion(it + 1, curr + *it, end);
}

int main() {
  vector<int> v({1});
  int res = recursion(begin(v), 0, end(v));
  cout << res << endl;
}