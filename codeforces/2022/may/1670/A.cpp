#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++)
      cin >> v[i];

    int start = 0;
    int end = k - 1;
    int positive = 0;
    int negative = 0;

    while(start < k - 1 && (abs(v[start + 1]) < abs(v[start]) || v[start + 1] == v[start])) {
      if(v[start] > 0)
        positive++;
      start++;
    }
    while(end > start && (abs(v[end - 1]) <= abs(v[end]) || v[end - 1] == v[end])) {
      if(v[end] < 0)
        negative++;
      end--;
    }

//    cout << start << ' ' << end << endl;
//    cout << positive << ' ' << negative << endl;

    if(start != end || negative != positive)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}