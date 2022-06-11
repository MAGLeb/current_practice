#include <bits/stdc++.h>

using namespace std;

int convert_to_int(const char &c) {
  return (int) c - 96;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s, winner;
    cin >> s;
    int res = 0;
    if(s.size() == 1) {
      res += convert_to_int(s[0]);
      winner = "Bob";
    } else {
      winner = "Alice";
      int start = 0;
      int end = s.size();
      if (s.size() % 2 == 1) {
        if (convert_to_int(s.front()) < convert_to_int(s.back()))
          res -= convert_to_int(s[start++]);
        else
          res -= convert_to_int(s[--end]);
      }

      for(; start < end; start++)
        res += convert_to_int(s[start]);
    }

    cout << winner << ' ' << res << endl;
  }
}