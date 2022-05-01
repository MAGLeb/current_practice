#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> one_day({1, 3, 5, 7, 8, 10, 12});
  uint64_t answer = 0;
  int day_week = 1;

  for (int year = 1901; year < 2001; year++) {
    for (int i = 1; i < 13; i++) {
      int day_month;
      if (day_week == 6)
        answer += 1;
      if (i == 2) {
        if (year % 4 == 0 && year % 400 != 0)
          day_month = 29;
        else
          day_month = 28;
      } else if (find(begin(one_day), end(one_day), i) != end(one_day))
        day_month = 31;
      else
        day_month = 30;

      day_week += day_month % 7;
      day_week %= 7;
    }
  }
  cout << answer << endl;
}