#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<pair<char, int>> seq;
  int n;
  cin >> n;
  int k = 0;
  char prev = '0';

  while (n--) {
    char c;
    cin >> c;
    if(prev != '0') {
      if(c == prev)
        k++;
      else
        seq.push_back(make_pair(prev, k));
        k = 0;
    }
    prev = c;
  }
}

/*
RBWBW
10202
102002

0000001002011110
5-0; 1-1; 2-0; 1-2; 1-0; 4-1; 1-0
5121141
