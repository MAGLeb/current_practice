#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename IT> void PrintReverse(IT begin_it, IT end_it) {
  bool first = true;
  while (end_it != begin_it) {
    --end_it;
    if(first) {
      cout << *end_it;
      first = false;
    } else {
      cout << " " << *end_it;
    }
  }
}

void PrintVectorPart(const vector<int> &numbers) {
  auto first_negative_it =
      find_if(begin(numbers), end(numbers), [](const int &x) { return x < 0; });

  PrintReverse(begin(numbers), first_negative_it);
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4}); // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}