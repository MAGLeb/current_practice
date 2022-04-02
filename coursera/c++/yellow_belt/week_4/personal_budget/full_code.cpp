#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Data {
private:
  string full_date;
  int year;
  int month;
  int day;

public:
  void ParseDate(string date);
  time_t AsTimestamp() const;
};

int ComputeDiff(const Data &start, const Data &end);

istream &operator>>(istream &is, Data &d);
ostream &operator<<(ostream &os, const Data &d);

enum class TypeQuery { Earn, ComputeIncome };

struct Query {
  TypeQuery name;
  Data start;
  Data end;
  double value;
};

istream &operator>>(istream &is, Query &q);

class Budget {
public:
  Data start;
  Data end;
  vector<double> budget;

  void Earn(Query &q);
  void ComputeIncome(Query &q);
};

istream &operator>>(istream &is, Query &q) {
  string query_type;
  is >> query_type;

  if (query_type == "Earn")
    q.name = TypeQuery::Earn;
  else if (query_type == "ComputeIncome")
    q.name = TypeQuery::ComputeIncome;

  is >> q.start;
  is >> q.end;

  if (q.name == TypeQuery::Earn)
    is >> q.value;

  return is;
}

int ConvertToInt(string str) {
  size_t pos;
  const int result = stoi(str, &pos);
  return result;
}

void Data::ParseDate(string date) {
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

time_t Data::AsTimestamp() const {
  tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_mday = day;
  t.tm_mon = month - 1;
  t.tm_year = year - 1900;
  t.tm_isdst = 0;
  return mktime(&t);
}

int ComputeDiff(const Data &start, const Data &end) {
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

void Budget::Earn(Query &q) {
  auto start_index = ComputeDiff(start, q.start);
  auto end_index = ComputeDiff(start, q.end);
  double value = q.value / (ComputeDiff(q.start, q.end) + 1);
  for (; start_index <= end_index; start_index++) {
    budget[start_index] += value;
  }
}

void Budget::ComputeIncome(Query &q) {
  auto start_index = ComputeDiff(start, q.start);
  auto end_index = ComputeDiff(start, q.end);
  cout << accumulate(begin(budget) + start_index, begin(budget) + end_index + 1,
                     0.)
       << endl;
}

int main() {
  cout.precision(25);
  Budget b;
  b.start.ParseDate(("2000-01-01"));
  b.end.ParseDate(("2100-01-01"));
  b.budget.resize(ComputeDiff(b.start, b.end), .0);

  Query q;
  int n;
  cin >> n;

  while (n--) {
    cin >> q;
    if (q.name == TypeQuery::Earn) {
      b.Earn(q);
    } else if (q.name == TypeQuery::ComputeIncome) {
      b.ComputeIncome(q);
    } else {
      throw invalid_argument("No command type!!!");
    }
  }

  return 0;
}