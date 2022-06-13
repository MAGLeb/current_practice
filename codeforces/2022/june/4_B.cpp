#include <bits/stdc++.h>

using namespace std;

void solve() {
  int d, sm;
  cin >> d >> sm;
  vector<int> mN(d);
  vector<int> mX(d);

  for (int i = 0; i < d; ++i)
    cin >> mN[i] >> mX[i];


  int diff = sm - accumulate(mN.begin(), mN.end(), 0);
  if (accumulate(mN.begin(), mN.end(), 0) <= sm and sm <= accumulate(mX.begin(), mX.end(), 0)) {
    cout << "YES"s << endl;

    int i = 0;
    while (diff > 0) {
      if (mX[i] - mN[i] < diff) {
        diff -= mX[i] - mN[i];
        mN[i] = mX[i];
      } else {
        mN[i] += diff;
        diff = 0;
      }
      ++i;
    }
    for(auto val : mN)
      cout << val << ' ';
  } else
    cout << "NO"s << endl;
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

  solve();

  return 0;
}