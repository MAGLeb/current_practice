#include <bits/stdc++.h>

using namespace std;

void solve() { return; }

int main() {
  int n;
  cin >> n;

  while (n--) {
    int m, inter;
    int mA = 0, mB = 0;

    cin >> m;
    while (m--) {
      cin >> inter;
      mA = max(mA, inter);
    }
    cin >> m;
    while (m--) {
      cin >> inter;
      mB = max(mB, inter);
    }

    if(mB == mA) {
      cout << "Alice" << endl;
      cout << "Bob" << endl;
    } else if(mB > mA) {
      cout << "Bob" << endl;
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
      cout << "Alice" << endl;
    }

  }
  return 0;
}