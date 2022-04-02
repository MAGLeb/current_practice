#include <numeric>

using namespace std;

#include "budget.h"
#include "data.h"
#include "query.h"

void Budget::Earn(Query &q) {
  int start_index = ComputeDiff(start, q.start);
  int end_index = ComputeDiff(start, q.end);
  double value = q.value / ((end_index - start_index) + 1);
  for (; start_index <= end_index; start_index++) {
    budget.at(start_index) += value;
  }
}

void Budget::ComputeIncome(Query &q) {
  int start_index = ComputeDiff(start, q.start);
  int end_index = ComputeDiff(start, q.end);
  cout << accumulate(begin(budget) + start_index, begin(budget) + end_index + 1,
                     0.0)
       << endl;
}