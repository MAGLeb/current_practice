#include <bits/stdc++.h>

using namespace std;

const int delimiters(const uint64_t &n) {
  uint64_t i = n;
  int delimiter = 2;
  set<uint64_t> unique({1});

  while (i != 1) {
    while (i % delimiter != 0)
      delimiter++;
    i = i / delimiter;

    set<uint64_t> second_unique;

    for(auto el : unique)
      second_unique.insert(el * delimiter);

    unique.insert(begin(second_unique), end(second_unique));
  }

  return unique.size();
}

int main() {
  uint64_t triangle = 1;
  int result = 1;
  uint64_t increment = 2;

  while (result < 500) {
    triangle += increment;
    ++increment;
    result = delimiters(triangle);
  }
  cout << increment << "triangle: " << triangle << " result: " << result << endl;
}