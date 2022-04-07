#include <bits/stdc++.h>

using namespace std;

int main() {
  set<char> chars({'a', 'o', 'u', 'e', 'i'});
  string s;
  int counter;
  bool flag = true;

  for(int i = 3; i > 0; --i) {
    if(i % 2)
      counter = 5;
    else
      counter = 7;

    getline(cin, s);
    for(char c : s) {
      if(chars.count(c))
        --counter;
    }

    if(counter != 0) {
      flag = false;
    }
  }

  if(flag)
    cout << "YES";
  else
    cout << "NO";
}