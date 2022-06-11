#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while(n--) {
    string s, t;
    cin >> s >> t;

    if(t == "a") {
      cout << 1 << endl;
    } else if(t.find('a') != string::npos) {
      cout << -1 << endl;
    } else {
      uint64_t res = pow(2, s.size());
      cout << res << endl;
    }
  }
}

