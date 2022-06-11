#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> height(n);

  for (int i = 0; i < n; ++i)
    cin >> height[i];

  sort(begin(height), end(height));

  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (height[j] - height[i] <= d)
        result++;
      else
        break;
    }
  }
  cout << result * 2 << endl;
}