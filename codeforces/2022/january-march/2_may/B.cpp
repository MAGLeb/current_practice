#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  map<string, int> mapper;

  int counter = 1;
  for(int i = 0; i < alphabet.size(); i++) {
    for(int j = 0; j < alphabet.size(); j++) {
      if(i == j)
        continue;
      stringstream ss;
      ss << alphabet[i] << alphabet[j];
      mapper[ss.str()] = counter++;
    }
  }

  while(n--) {
    string s;
    cin >> s;
    cout << mapper[s] << endl;
  }
}