#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int WINDOW_SIZE = 4;

const int right(const int &j, const vector<int> &row) {
  if (j + WINDOW_SIZE > row.size())
    return 0;
  int result = 1;

  for (int column = j; column < j + WINDOW_SIZE; ++column) {
    result *= row[column];
  }
  return result;
}

const int down(const int &i, const int &j, const vector<vector<int>> &grid) {
  if (i + WINDOW_SIZE > grid.size())
    return 0;
  int result = 1;

  for (int row = i; row < i + WINDOW_SIZE; ++row) {
    result *= grid[row][j];
  }
  return result;
}

const int diagonal_right(const int &i, const int &j,
                   const vector<vector<int>> &grid) {
  if (j + WINDOW_SIZE > grid.size() || i + WINDOW_SIZE > grid.size())
    return 0;

  int result = 1;

  for (int counter = 0; counter < WINDOW_SIZE; ++counter) {
    result *= grid[i + counter][j + counter];
  }
  return result;
}

const int diagonal_left(const int &i, const int &j,
                        const vector<vector<int>> &grid) {
  if (j - WINDOW_SIZE < 0 || i + WINDOW_SIZE > grid.size())
    return 0;

  int result = 1;

  for (int counter = WINDOW_SIZE - 1; counter >= 0; --counter) {
    result *= grid[i + counter][j - counter];
  }
  return result;
}

const void print_grid(const vector<vector<int>> &grid) {
  for(auto row : grid) {
    for(auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> grid;
  fstream file("11.txt");
  int n, m;
  file >> n >> m;

  for (int i = 0; i < n; ++i) {
    vector<int> row;
    for (int j = 0; j < m; ++j) {
      int v;
      file >> v;
      row.push_back(v);
    }
    grid.push_back(row);
  }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      result = max(right(j, grid[i]), result);
      result = max(down(i, j, grid), result);
      result = max(diagonal_right(i, j, grid), result);
      result = max(diagonal_left(i, j, grid), result);
    }
  }

  cout << result << endl;
}