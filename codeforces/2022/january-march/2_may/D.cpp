#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    vector<int> a(k, 0);
    vector<int> b(k, 0);
    vector<int> c(k, 0);

    for (int i = 0; i < k; i++)
      cin >> a[i];

    int start = 0;
    int end = k - 1;
    while (start < end) {
      int val = a[end - start];
      if (b[start] < val) {
        b[start++] = val;
      } else {
        b[end--] = val;
      }
    }

    for (auto val : a) {
      cout << val << ' ';
    }
    cout << endl;

    for (auto val : b) {
      cout << val << ' ';
    }
    cout << endl;
  }
}