#include <bits/stdc++.h>

using namespace std;

int main() {
  int mx = 2;
  int longest = 1;
  for (int denominator = 2; denominator < 1000; denominator++) {
    int numerator = 1;
    int res = 0;
    set<int> setter;

    while (true) {
      if (numerator == 0)
        break;
      while (numerator < denominator)
        numerator *= 10;
      numerator %= denominator;
      if (setter.find(numerator) != end(setter)) {
        if(res > longest) {
          mx = denominator;
          longest = res;
        }
        break;
      } else {
        setter.insert(numerator);
      }
      res += 1;
    }
  }
  cout << "number with longest decimal circle is: " << mx << " with cirle: " << longest << endl;
}