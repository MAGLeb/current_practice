#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  vector<string> str({"2223", "0003", "3", "03"});
  string date;

  for (string s : str) {
    int q = stoi(s);
    cout << q << endl;
  }
  date = to_string(stoi(str[0])) + '-' + to_string(stoi(str[1])) + '-' + "29";

  cout << date;
}