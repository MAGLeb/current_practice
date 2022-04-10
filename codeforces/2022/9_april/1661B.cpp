#include <bits/stdc++.h>

using namespace std;

int y = 32768;

int find_mod(int x, int result) {
  if(x > y)
    return INT32_MAX;
  if(x == y)
    return result;
  return min(find_mod(x * 2, result + 1), find_mod(x + 1, result + 1));
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    int w;
    cin >> w;
    cout << find_mod(w, 0) << endl;
  }
}