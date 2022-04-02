#pragma once

#include <iostream>

using namespace std;

#include "data.h"

enum class TypeQuery { Earn, ComputeIncome };

struct Query {
  TypeQuery name;
  Data start;
  Data end;
  double value;
};

istream &operator>>(istream &is, Query &q);