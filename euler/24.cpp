#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
  if (n == 1)
    return 1;
  return n * factorial(n - 1);
}

int main() {
  vector<int> digits({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  string answer = "";
  int n = 1'000'000;
  for (int i = 9; i >= 0; i--) {
    int inter = 1;
    int fact = factorial(i);
    for (int j = 0; j < digits.size(); j++) {
      if ((digits[j] + 1) * fact >= n || j == digits.size() - 1) {
        if ((digits[j] + 1) * fact >= n)
          j--;
        inter = (digits[j] + 1) * fact;
        answer += to_string(digits[j]);
        cout << "inter: " << inter;
        cout << " answer: " << answer;
        cout << " n: " << n;
        cout << endl;
        digits.erase(begin(digits) + j);
        break;
      }
    }

    n -= inter;
  }
  cout << answer << endl;
}