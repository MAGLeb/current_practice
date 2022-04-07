#include <bits/stdc++.h>

using namespace std;

bool comparator_lower(const string &s, const char &c) { return s[0] < c; }

bool comparator_upper(const char &c, const string &s) { return s[0] > c; }

bool comparator(const string &s, const string &c) { return s[0] < c[0]; }

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
                                        RandomIt range_end, char prefix) {
  return equal_range(range_begin, range_end, string(1, prefix), comparator);

  //  return make_pair(
  //      lower_bound(range_begin, range_end, prefix, comparator_lower),
  //      upper_bound(range_begin, range_end, prefix, comparator_upper));
}

bool comparator_strings_lower(const string &s, const string &val) {
  auto it_1 = begin(s);
  auto it_2 = begin(val);

  while(it_1 != end(s) && it_2 != end(val)) {
    if(*it_1 == *it_2) {
      ++it_1, ++it_2;
      continue;
    }
    return *it_1 < *it_2;
  }
  return false;
}

bool comparator_strings_upper(const string &val, const string &s) {
  auto it_1 = begin(s);
  auto it_2 = begin(val);

  while(it_1 != end(s) && it_2 != end(val)) {
    if(*it_1 == *it_2) {
      ++it_1, ++it_2;
      continue;
    }
    return *it_1 > *it_2;
  }
  return s.size() < val.size();
}

bool comparator_strings(const string &s, const string &val) {
  auto it_1 = begin(s);
  auto it_2 = begin(val);

  while(it_1 != end(s) && it_2 != end(val)) {
    if(*it_1 == *it_2) {
      ++it_1, ++it_2;
      continue;
    }
    return *it_1 <= *it_2;
  }
  return s.size() > val.size();
}

template <typename RandomIt>
pair<RandomIt, RandomIt>
FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix) {
  return equal_range(range_begin, range_end, prefix, [&](auto const& lhs, auto const& rhs) {
    size_t const size = prefix.size();
    return lhs.compare(0, size, rhs, 0, size) < 0;
  });
//    return make_pair(
//        lower_bound(range_begin, range_end, prefix, comparator_strings_lower),
//        upper_bound(range_begin, range_end, prefix, comparator_strings_upper));
}

int main() {
  string a = "aaa";
  string aa = "aaaaa";
  cout << comparator_strings(a, aa) << endl;
  cout << a.compare(aa) << endl;
  cout << aa.compare(a) << endl;
  const vector<string> sorted_strings = {"asdf", "mosa", "moscow", "motovilikha", "murmansk"};

  auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  cout << (mt_result.first - begin(sorted_strings)) << " "
       << (mt_result.second - begin(sorted_strings)) << endl;

  mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mosco");
  cout << (mt_result.first - begin(sorted_strings)) << " "
       << (mt_result.second - begin(sorted_strings)) << endl;

  mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mosaw");
  cout << (mt_result.first - begin(sorted_strings)) << " "
       << (mt_result.second - begin(sorted_strings)) << endl;

  mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "baba");
  cout << (mt_result.first - begin(sorted_strings)) << " "
       << (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " "
       << (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}