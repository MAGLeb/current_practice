#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix;

    for (int i = 0; i < r; i++) {
      vector<int> row(c);
      for (int j = 0; j < c; j++) {
        cin >> row[j];
      }
      matrix.push_back(row);
    }

    int res = 0;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int inter = matrix[i][j];

        int i_= i+1;
        int j_ = j+1;
        while(i_ < r && j_ < c)
          inter += matrix[i_++][j_++];
        i_= i-1;
        j_ = j-1;
        while(i_ >= 0 && j_ >= 0)
          inter += matrix[i_--][j_--];
        i_= i-1;
        j_ = j+1;
        while(i_ >= 0 && j_ < c)
          inter += matrix[i_--][j_++];
        i_= i+1;
        j_ = j-1;
        while(i_ < r && j_ >= 0)
          inter += matrix[i_++][j_--];
        res = max(res, inter);
      }
    }

    cout << res << endl;
  }
}