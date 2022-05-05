#include <bits/stdc++.h>

using namespace std;

int main() {
  int res = 0;
  int n = 5;
  for(int i = 2; i < pow(9, n) * 6; i++) {
    string s = to_string(i);
    int inter = 0;
    for(char c : s) {
      inter += pow((int) c - 48, n);
    }
    string s_ = to_string(inter);
    if(s == s_) {
      res += stoi(s);
      cout << s << endl;
    }
  }

  cout << res << endl;
}