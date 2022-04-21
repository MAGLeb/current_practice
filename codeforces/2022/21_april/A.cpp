#include <bits/stdc++.h>

using namespace std;

int main() {
  string div = "Division ";
  int n;
  cin >>n;

  while(n--) {
    int r;
    int res;
    cin >>r;
    if(r>=1900)
      res = 1;
    else if(r>=1600)
      res = 2;
    else if(r>=1400)
      res = 3;
    else
      res = 4;
    cout << div << res << endl;
  }
}