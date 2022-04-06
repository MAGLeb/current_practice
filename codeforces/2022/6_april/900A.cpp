#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int l = 0;
  int r = 0;

  while(n--) {
    int x, y;
    cin >> x >> y;
    if(x < 0)
      ++l;
    else
      ++r;

    if(l > 1 && r > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;

}