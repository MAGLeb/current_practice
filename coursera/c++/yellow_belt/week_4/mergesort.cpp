#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if(range_end - range_begin < 2)
    return;
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  int step = elements.size() / 3;
  auto first_mid = begin(elements) + step;
  auto second_mid = begin(elements) + step * 2;

  MergeSort(begin(elements), first_mid);
  MergeSort(first_mid, second_mid);
  MergeSort(second_mid, end(elements));

  vector<typename RandomIt::value_type> intermediate;

  merge(begin(elements), first_mid, first_mid, second_mid, back_inserter(intermediate));
  merge(begin(intermediate), end(intermediate), second_mid, end(elements), range_begin);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}