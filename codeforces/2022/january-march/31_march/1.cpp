#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  while(n--) {
    int a, b;
    cin >> a >> b;

    if(a == 0) {
      cout << 1 << endl;
    } else {
      cout << a + b * 2 + 1 << endl;
    }
  }
}