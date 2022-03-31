#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  bool first = true;
  for (auto &val : v) {
    if (first) {
      first = false;
      os << val;
    } else {
      os << " " << val;
    }
  }
  return os;
}

void PrintCombinations(const int &n) {
  vector<int> numbers;

  for (int i = n; i > 0; --i)
    numbers.push_back(i);

  do {
    cout << numbers << endl;
  } while (prev_permutation(numbers.begin(), numbers.end()));
}

int main() {
  int n;
  cin >> n;
  PrintCombinations(n);
}