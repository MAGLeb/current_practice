#include <bits/stdc++.h>

using namespace std;

char prev_char(char c) {
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int n = (int)c - 97;
  if (n == 0)
    n = 26;
  n--;
  return alpha[n];
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    int l, k;
    cin >> l >> k >> s;

    int i = 0;
    while(i < s.size()) {
      while((int) s[i] - 97 < k && i < s.size())
        i++;
      char curr = s[i];
      char initial = s[i];
      while(curr != 'a' && k > 0) {
        curr = prev_char(curr);
        k--;
      }
      for(int j = 0; j < s.size(); j++) {
        if(s[j] > curr && s[j] <= initial)
          s[j] = curr;
      }
      i++;
    }

    cout << s << endl;
  }
}