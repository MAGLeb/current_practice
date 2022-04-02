#include <iostream>

using namespace std;

#include "query.h"
#include "budget.h"
#include "data.h"

int main() {
  cout.precision(25);
  Budget b;
  b.start.ParseDate(("2000-01-01"));
  b.end.ParseDate(("2100-01-01"));
  b.budget.resize(ComputeDiff(b.start, b.end));

  Query q;
  int n;
  cin >> n;

  while (n--) {
    cin >> q;
    if(q.name == TypeQuery::Earn) {
      b.Earn(q);
    } else if(q.name == TypeQuery::ComputeIncome) {
      b.ComputeIncome(q);
    } else {
      throw invalid_argument("No command type!!!");
    }
  }

  return 0;
}