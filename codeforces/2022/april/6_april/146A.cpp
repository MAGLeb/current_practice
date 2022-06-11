#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  map<char, int> counter = {{'4', 0}, {'7', 0}};

  for(int i = 0; i < s.size(); ++i) {
    if(i < s.size() / 2)
      ++counter[s[i]];
    else
      --counter[s[i]];

    if((s[i] != '4' && s[i] != '7') || counter[s[i]] == -1) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}