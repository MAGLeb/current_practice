#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> names;

  cout << (int)'A' - 64 << endl;
  cout << (int)'C' - 64 << endl;
  cout << numeric_limits<uint64_t>::max() << endl;

  fstream ss;
  ss.open("/home/magleb/current_practice/euler/inputs/p022_names.txt");
  string name;
  while (getline(ss, name, ','))
    names.push_back(name.substr(1, name.size() - 2));

  sort(begin(names), end(names));

  uint64_t res = 0;
  for (int i = 0; i < names.size(); i++) {
    int sl = 0;
    for (auto letter : names[i]) {
      sl += (int)letter - 64;
    }
    res += (i + 1) * sl;
  }

  cout << res << endl;
}