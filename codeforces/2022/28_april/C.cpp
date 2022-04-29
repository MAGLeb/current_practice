#include <bits/stdc++.h>

using namespace std;

struct Point {
  Point(const int x_, const int w_, const int i_) {
    x = x_;
    w = w_;
    i = i_;
  }

  int x;
  int w;
  int i;
};

int main() {
  string blank;
  int t;
  cin >> t;

  while (t--) {
    getline(cin, blank);
    int n, m, k;
    cin >> n >> m;
    vector<Point> points_w;
    k = m;
    while (k--) {
      int x, w;
      cin >> x >> w;
      Point p = Point(x, w, m - k);
      points_w.push_back(p);
    }
    sort(begin(points_w), end(points_w),
         [](const Point &f, const Point &s) { return f.w < s.w; });

    points_w.erase(begin(points_w) + n * 2, end(points_w));

    sort(begin(points_w), end(points_w),
         [](const Point &f, const Point &s) { return f.x < s.x; });

    int result = 0;
    vector<pair<int, int>> v;

    auto i = begin(points_w);
    auto j = end(points_w) - 1;

    while(j - i > 0) {
      result += i->w + j->w;
      v.push_back(make_pair(i->i, j->i));
      i++;
      j--;
    }

    cout << result << endl;
    for (auto elem : v) {
      cout << elem.first << ' ' << elem.second << endl;
    }
    if (t != 0)
      cout << endl;
  }
}