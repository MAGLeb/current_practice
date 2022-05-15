#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    vector<int> v;
    string s;
    cin >> s;

    int zeroes = 0;
    int ones = 0;
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
      counter++;
      if (s[i] == '0')
        zeroes++;

      if (i+1 == s.size() || s[i] != s[i+1]) {
        if (s[i] == '0')
          v.push_back(-counter);
        else
          v.push_back(counter);
        counter = 0;
      }
    }

//    for (auto val : v) {
//      cout << val << ' ';
//      cout << endl;
//    }
//    cout << "res: " << zeroes << endl;

    int start = 0;
    int end = v.size() - 1;
    int res = max(zeroes, ones);

    if (start == end) {
      res = 0;
    } else {
      while(start < end) {
        int curr;
        if(v[start] < v[end])
          curr = v[start++];
        else
          curr = v[end--];

        if(curr < 0)
          zeroes += curr;
        else
          ones += curr;
        res = min(res, max(zeroes, ones));
      }
    }
    cout << res << endl;
  }
}