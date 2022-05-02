#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> curr(1000, 0);
  vector<int> prev(1000, 0);
  curr[0] = 1;
  prev[0] = 1;

  int res = 2;
  while(curr[curr.size() - 1] == 0) {
    res++;
    vector<int> inter = curr;
    for(int i = 0; i < curr.size(); i++) {
      curr[i] += prev[i];
      int k = i;
      while (curr[k] > 9) {
        curr[k + 1] += curr[k] / 10;
        curr[k++] %= 10;
      }
    }
    prev = inter;
  }

  cout << res << endl;
}