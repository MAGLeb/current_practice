#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int r, c;
    cin >> r >> c;
    vector<vector<pair<int, int>>> matrix;

    for (int i = 0; i < r; i++) {
      vector<pair<int, int>> row(c);
      for (int j = 0; j < c; j++) {
        cin >> row[j].first;
        row[j].second = j;
      }
      sort(row.begin(), row.end());
      matrix.push_back(row);
    }

    pair<int, int> result = make_pair(-2, -2);
    bool correctness = true;

    for (int i = 0; i < c; i++) {
      if (matrix[0][i].second != i) {
        if (result.first != -2) {
          correctness = false;
          break;
        }
        result = make_pair(matrix[0][i].second, matrix[0][matrix[0][i].second].second);
        swap(matrix[0][i].first, matrix[0][matrix[0][i].second].first);
        swap(matrix[0][i].second, matrix[0][matrix[0][i].second].second);
        i--;
      }
    }

    for (int j = 1; j < r; j++) {
      if (!correctness)
        break;
      pair<int, int> res = make_pair(-2, -2);
      for (int i = 0; i < c; i++) {
        if (matrix[j][i].second != i) {
          if (res.first != -2 || i != result.first) {
            correctness = false;
            break;
          }
          result = make_pair(matrix[j][i].second, matrix[j][matrix[j][i].second].second);
          swap(matrix[j][i].first, matrix[j][matrix[j][i].second].first);
          swap(matrix[j][i].second, matrix[j][matrix[j][i].second].second);
        }
        i--;
      }
    }

    //    pair<int, int> result = make_pair(-2, -2);
    //    bool correctness = true;
    //    bool swapped = false;
    //
    //    for (int i = 0; i < c; i++) {
    //      int curr_index = matrix[0][i].second;
    //
    //      if (curr_index != i && swapped) {
    //        correctness = false;
    //        break;
    //      }
    //
    //      for (int j = 0; j < r; j++) {
    //        if (matrix[j][i].second != curr_index && matrix[j][i].first !=
    //        matrix[j][curr_index].first) {
    //          correctness = false;
    //          break;
    //        }
    //      }
    //
    //      if (curr_index != i) {
    //        swapped = true;
    //        curr_index = matrix[0][matrix[0][i].second].second;
    //        result = make_pair(matrix[0][matrix[0][i].second].second + 1,
    //        matrix[0][i].second + 1);
    //
    //        for (int j = 0; j < r; j++) {
    //          if(matrix[j][i].first == matrix[j][matrix[j][i].second].first)
    //            continue;
    //          swap(matrix[j][i].first, matrix[j][matrix[j][i].second].first);
    //          swap(matrix[j][i].second,
    //          matrix[j][matrix[j][i].second].second);
    //
    //          if (curr_index != matrix[j][i].second) {
    //            correctness = false;
    //            break;
    //          }
    //        }
    //        i--;
    //      }
    //
    //      if (!correctness)
    //        break;
    //    }

    if (correctness) {
      if (result.first == -2)
        cout << 1 << ' ' << 1 << endl;
      else
        cout << result.first << ' ' << result.second << endl;
    } else
      cout << -1 << endl;
  }
}