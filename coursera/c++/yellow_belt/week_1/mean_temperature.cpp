#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n, input;
  float average;
  int result = 0;
  vector<int> temp;
  vector<int> res_vec;

  cin >> n;
  while(n--) {
    cin >> input;
    temp.push_back(input);
  }

  average = accumulate(temp.begin(), temp.end(), 0.0) / static_cast<float>(temp.size());

  for(int i = 0; i < temp.size(); ++i) {
    if(temp[i] > average) {
      ++result;
      res_vec.push_back(i);
    }
  }

  cout << result << endl;
  for(int res : res_vec)
    cout << res << " ";
}