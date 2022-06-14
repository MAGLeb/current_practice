#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(const string &time) {
  return (time[0] == time[4]) and (time[1] == time[3]);
}

string convert_int_to_string(int number) {
  string s = to_string(number);
  if(s.size() == 1)
    s = '0' + s;
  return s;
}

string add_minutes(string curr_time, int min_iter) {
  int hour = stoi(curr_time.substr(0, 2));
  int minutes = stoi(curr_time.substr(3, 5));

  minutes += min_iter;
  hour += (int)minutes / 60;
  minutes %= 60;
  hour %= 24;

  string result = convert_int_to_string(hour) + ":" + convert_int_to_string(minutes);
  return result;
}

void solve() {
  int k;
  string time;
  cin >> time >> k;
  set<string> s = {time};
  int result = 0;
  if(is_palindrome(time))
    ++result;
  do {
    time = add_minutes(time, k);
    if (s.count(time))
      break;
    s.insert(time);
    if(is_palindrome(time)) {
      ++result;
    }
  } while (true);

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