#include "utils.h"

using namespace std;

ostream &operator<<(ostream &os, const pair<Date, string> &p) {
  os << p.first << ' ' << p.second;
  return os;
}

ostream &operator<<(ostream &os, const Date &d) {
  os << d.GetDate();
  return os;
}