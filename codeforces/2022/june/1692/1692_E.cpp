#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> v(n);

  int k = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == 1)
      ++k;
  }

  int result = 0;
  int start = 0;
  int end = n - 1;
  int start_d = 0;
  int end_d = 0;

  while (k != s) {
    while (v[start] != 1 and start < end) {
      ++start;
      ++start_d;
    }
    while (v[end] != 1 and end > start) {
      --end;
      ++end_d;
    }

    if (start > end) {
      result = -1;
      break;
    }

    if (start_d < end_d) {
      result += start_d + 1;
      start_d = 0;
      ++start;
    } else {
      result += end_d + 1;
      end_d = 0;
      --end;
    }

    --k;
  }

  cout << result << endl;
}

void solve_() {
  int n, s;
  cin >> n >> s;
  vector<int> v(n);

  int k = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == 1)
      ++k;
  }

  int result = 0;

  while (k != s) {
    auto head = v.begin();
    auto tail = --v.end();

    while (*head != 1 and head != v.end()) {
      ++head;
    }
    while (*tail != 1 and tail != v.begin()) {
      --tail;
    }

    if (head == v.end()) {
      result = -1;
      break;
    }

    int head_distance = distance(v.begin(), head) + 1;
    int tail_distance = distance(tail, --v.end()) + 1;

    if (head_distance < tail_distance) {
      result += head_distance;
      v = vector<int>(v.begin() + head_distance, v.end());
    } else {
      result += tail_distance;
      v = vector<int>(v.begin(), v.end() - tail_distance);
    }
    --k;
  }

  cout << result << endl;

  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;

  while (n--) {
    solve();
  }

  return 0;
}