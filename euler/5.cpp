#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> delimiters;
  for (int i = 2; i <= 20; ++i) {
    int inter = i;
    for (auto delimiter : delimiters) {
      if (inter % delimiter == 0)
        inter /= delimiter;
    }
    delimiters.push_back(inter);
  }

  int result = 1;
  for (auto delimiter : delimiters) {
//    cout << "delimiter: " << delimiter << endl;
    result *= delimiter;
  }
  cout << result << endl;
}