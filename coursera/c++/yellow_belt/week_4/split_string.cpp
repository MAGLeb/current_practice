#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> result;

  auto it = begin(s);
  auto next = find(begin(s), end(s), ' ');

  while(next != end(s)) {
    result.push_back(string(it, next));
    it = next + 1;
    next = find(it, end(s), ' ');
  }
  result.push_back(string(it, next));

  return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}