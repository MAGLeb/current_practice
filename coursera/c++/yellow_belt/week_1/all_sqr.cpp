#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

template <typename T> T Sqr(T value);
template <typename First, Second>
pair<First, Second> Sqr(const pair<First, Second> &value);
template <typename T> vector<T> Sqr(const vector<T> &value);
template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> &value);

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> p) {
  return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value> m) {
  map<Key, Value> result;

  for (auto p : m) {
    result.insert({p.first, Sqr(p.second)});
  }
  return result;
}

template <typename T> vector<T> Sqr(vector<T> vi) {
  vector<T> result;

  for (auto val : vi) {
    result.push_back(Sqr(val));
  }
  return result;
}

template <typename T> T Sqr(T value) { return value * value; }

// int main() {
//   vector<int> v = {1, 2, 3};
//   cout << "vector:";
//   for (int x : Sqr(v)) {
//     cout << ' ' << x;
//   }
//   cout << endl;
//
//   map<int, pair<int, int>> map_of_pairs = {
//       {4, {2, 2}},
//       {7, {4, 3}}
//   };
//   cout << "map of pairs:" << endl;
//   for (const auto& x : Sqr(map_of_pairs)) {
//     cout << x.first << ' ' << x.second.first << ' ' << x.second.second <<
//     endl;
//   }
// }