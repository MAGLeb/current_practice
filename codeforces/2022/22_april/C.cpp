#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int m, x, res = 0;
    cin >> m >> x;
    int n = m;
    vector<int> v(m);

    while(m > 0)
      cin >> v[--m];
    sort(begin(v), end(v));

    int rest = 0;
    int curr = 0;
    int it_end = -1;

    int inter = x;
    for(int i = 0; i < v.size(); i++) {
      if(inter - v[i] < 0) {
        it_end = i - 1;
        break;
      }
      inter -= v[i];
      curr += v[i];
      res++;
    }
    if(it_end == -1)
      it_end = n - 1;
    rest = inter;

    while(it_end >= 0) {
      if(rest <= it_end) {
        curr -= v[it_end];
        curr += it_end;
        res += it_end;
        it_end--;
      } else {
        res += it_end + 1;
        curr += it_end + 1;
      }
      rest = x - curr;
    }


    cout << res << endl;

  }
}