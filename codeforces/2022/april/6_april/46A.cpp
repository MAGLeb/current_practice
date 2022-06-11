#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int last = 1;
  cin >> n;

  for(int i = 1; i < n; ++i) {
    last = (last + i) % n;
    if(last == 0)
      cout << n << " ";
    else
      cout << last << " ";
  }
}