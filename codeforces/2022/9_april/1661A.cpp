#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    vector<int> n_1(k);
    vector<int> n_2(k);

    for (int i = 0; i < k; ++i) {
      cin >> n_1[i];
    }
    for (int i = 0; i < k; ++i) {
      cin >> n_2[i];
    }

    int result = 0;
    for (int i = 1; i < k; ++i) {
      if (abs(n_1[i - 1] - n_1[i]) + abs(n_2[i - 1] - n_2[i]) >
          abs(n_1[i - 1] - n_2[i]) + abs(n_2[i - 1] - n_1[i])) {
        int tmp = n_1[i];
        n_1[i] = n_2[i];
        n_2[i] = tmp;
      }
      result += abs(n_1[i - 1] - n_1[i]) + abs(n_2[i - 1] - n_2[i]);
    }

    cout << result << endl;
  }
}