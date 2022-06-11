#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  map<string, int> letter_index;
  map<int, vector<pair<int, int>>> min_len_pair;
  vector<pair<int, int>> visited;
  int n;
  cin >> n;

  while (n--) {
    int result = 0;
    int counter = 0;
    string s;
    cin >> s;
    int i = 0;

    while(i < s.size()) {
      if(s[i] == s[i + 1]) {
        sort(begin(min_len_pair), end(min_len_pair));
        for (auto map_pair : min_len_pair) {
          for (auto min_pair : map_pair.second) {
            bool new_pair = true;

            for (auto segment : visited) {
              if (!((min_pair.first > segment.second &&
                     min_pair.second > segment.second) ||
                    (min_pair.first < segment.first &&
                     min_pair.second < segment.first))) {
                new_pair = false;
                break;
              }
            }
            if(new_pair) {
              result += map_pair.first - 1;
              counter -= map_pair.first + 1;
              visited.push_back(min_pair);
            }
          }
        }

        i += 2;
        letter_index.clear();
        min_len_pair.clear();
        visited.clear();
        result += counter;
        counter = 0;
        continue;
      }



      if (letter_index.find(s[i]) == end(letter_index)) {
        letter_index.insert(make_pair(s[i], i));
      } else {
        if(min_len_pair.find(i - letter_index[s[i]]) == end(min_len_pair)) {
          vector<pair<int, int>> new_pairs_vector;
          new_pairs_vector.push_back(pair<int, int>(letter_index[s[i]], i));
          min_len_pair.insert({pair<int, int>(i - letter_index[s[i]], new_pairs_vector)});
        } else {
          min_len_pair.at(i - letter_index[s[i]]).push_back(pair<int, int>(letter_index[s[i]], i));
        }
        letter_index.at(s[i]) = i;
      }
      i++;
      counter++;
    }
  }
}