#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    vector<int> val(4);
    cin >> val[0] >> val[1] >> val[2] >> val[3];
    sort(begin(val), end(val));
    cout << val[0] * val[2] << endl;
  }
}