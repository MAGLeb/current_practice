#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    string a;
    cin >> a;

    if(a.size() < 3)
      cout << a[1];
    else {
      int mN = numeric_limits<int>::max(), i;

      for(auto c : a) {
        i = c;
        i -= 48;
        if(i < mN)
          mN = i;
      }
      cout << mN;
    }
    cout << endl;
  }
}