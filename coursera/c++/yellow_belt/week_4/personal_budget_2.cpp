#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <numeric>

using namespace std;

int ConvertToInt(string str) {
  size_t pos;
  const int result = stoi(str, &pos);
  return result;
}

class Data {
private:
  string full_date;
  int year;
  int month;
  int day;

public:
  void ParseDate(string date) {
    full_date = date;

    auto it = begin(date);
    auto next = find(begin(date), end(date), '-');
    year = ConvertToInt(string(it, next));

    it = next + 1;
    next = find(it, end(date), '-');
    month = ConvertToInt(string(it, next));

    it = next + 1;
    next = find(it, end(date), '-');
    day = ConvertToInt(string(it, next));
  }

  time_t AsTimestamp() const {
    tm t;
    t.tm_sec  = 0;
    t.tm_min  = 0;
    t.tm_hour = 0;
    t.tm_mday = day;
    t.tm_mon  = month - 1;
    t.tm_year = year - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
  }
};

int ComputeDiff(const Data& start, const Data& end) {
  const time_t timestamp_to = start.AsTimestamp();
  const time_t timestamp_from = end.AsTimestamp();
  static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_from - timestamp_to) / SECONDS_IN_DAY;
}

istream &operator>>(istream &is, Data &d) {
  string s;
  is >> s;
  d.ParseDate(s);

  return is;
}

int main() {
  Data start;
  start.ParseDate("1700-01-01");
  Data end;
  end.ParseDate("2100-01-01");
  vector<uint64_t> budget(ComputeDiff(start, end), 0);
  vector<uint64_t> partial_budget(ComputeDiff(start, end), 0);

  string s;
  size_t n;
  cin >> n;
  while(n--) {
    uint64_t val;
    cin >> s >> val;
    Data input;
    input.ParseDate(s);
    int start_index = ComputeDiff(start, input);
    budget[start_index] = val;
  }
  partial_sum(budget.begin(), budget.end(), partial_budget.begin());

  cin >> n;
  while(n--) {
    cin >> s;
    Data input;
    input.ParseDate(s);
    cin >> s;
    Data output;
    output.ParseDate(s);

    uint64_t result = 0.0;
    auto start_index = ComputeDiff(start, input);
    auto end_index = ComputeDiff(start, output);

    if(start_index > 0)
      cout << partial_budget[end_index] - partial_budget[start_index - 1] << endl;
    else
      cout << partial_budget[end_index] << endl;
  }
}