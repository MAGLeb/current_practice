#include <string>

using namespace std;

#include "query.h"

istream &operator>>(istream &is, Query &q) {
  string query_type;
  is >> query_type;

  if (query_type == "Earn")
    q.name = TypeQuery::Earn;
  else if(query_type == "ComputeIncome")
    q.name = TypeQuery::ComputeIncome;

  is >> q.start;
  is >> q.end;

  if (q.name == TypeQuery::Earn)
    is >> q.value;

  return is;
}
