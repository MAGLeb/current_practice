#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n != 0) {
    int m;
    int zeroes = 0;
    int ones = 0;
    string str;
    int result = 0;
    vector<int> sizes;
    cin >> m;

    while (m != 0) {
      cin >> str;

      for (auto letter : str) {
        if (letter == '0')
          ++zeroes;
        else
          ++ones;
      }
      sizes.push_back(str.size());
      --m;
    }

    sort(sizes.begin(), sizes.end());

    for (auto s : sizes) {
      while (s != 0) {
        if (s == 1) {
          if (zeroes % 2 == 1)
            --zeroes;
          else if (ones % 2 == 1)
            --ones;
          else {
            if(zeroes != 0)
              --zeroes;
            else if(ones != 0)
              --ones;
            else
              break;
          }
          --s;
          break;
        }

        if(zeroes > 1)
          zeroes -= 2;
        else if(ones > 1)
          ones -= 2;
        else
          break;

        s -= 2;
      }

      if (s != 0)
        break;

      ++result;
    }

    cout << result << endl;
    --n;
  }
}