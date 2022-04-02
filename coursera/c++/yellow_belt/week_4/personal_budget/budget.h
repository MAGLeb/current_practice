#pragma once

#include <vector>

using namespace std;

#include "query.h"
#include "data.h"

class Budget {
public:
  Data start;
  Data end;
  vector<double> budget;

  void Earn(Query &q);
  void ComputeIncome(Query &q);
};