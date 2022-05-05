#include <bits/stdc++.h>

using namespace std;

int main() {
  map<int, string> mapper({{1, "one"},
                           {2, "two"},
                           {3, "three"},
                           {4, "four"},
                           {5, "five"},
                           {6, "six"},
                           {7, "seven"},
                           {8, "eight"},
                           {9, "nine"},
                           {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}});

  for(auto p : mapper) {
    cout << p.first << p.second << endl;
  }
}