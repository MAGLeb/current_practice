#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin>>n;
  while(n--) {
    string s;
    cin >> s;
    int start = 0;
    int end = s.size() - 1;
    for(int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        end = i;
        break;
      } else if(s[i] == '1') {
        start = i;
      }
    }
    cout << end - start + 1 << endl;
  }
}