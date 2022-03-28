#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y) {
  return x + y;
}

string Reverse(string s) {
  for(int i = 0; i < s.size() / 2; ++i) {
    swap(s[i], s[s.size() - i - 1]);
  }
  return s;
}

void Sort(vector<int>& nums) {
  sort(nums.begin(), nums.end());
}

