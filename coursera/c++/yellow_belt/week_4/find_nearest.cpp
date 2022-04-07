#include <bits/stdc++.h>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int> &numbers,
                                            int border) {
  // set<int>::const_iterator —
  // тип итераторов для константного множества целых чисел
  if(numbers.empty())
    return end(numbers);

  auto lower = numbers.lower_bound(border);
  auto upper = lower--;
  if(upper == end(numbers)) {
    return lower;
  }else if(upper == begin(numbers)) {
    return upper;
  } else {
    return (border - *lower <= *upper - border) ? lower : upper;
  }
}

int main() {
  set<int> numbers = {1, 7, 10};
  cout << *FindNearestElement(numbers, -19) << " "
       << *FindNearestElement(numbers, 0) << " "
       << *FindNearestElement(numbers, 1) << " "
       << *FindNearestElement(numbers, 4) << " "
       << *FindNearestElement(numbers, 7) << " "
       << *FindNearestElement(numbers, 8) << " "
       << *FindNearestElement(numbers, 9) << " "
       << *FindNearestElement(numbers, 11) << " "
       << *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
