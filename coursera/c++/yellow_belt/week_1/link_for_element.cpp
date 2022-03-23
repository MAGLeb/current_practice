#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &m, Key key);

template <typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &m, Key key) {
  if (m.find(key) == m.end()) {
    throw runtime_error("Don't find key in map!");
  }
  return m.at(key);
}

int main() {
  map<int, string> m = {{0, "value"}};
  string &item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue
}