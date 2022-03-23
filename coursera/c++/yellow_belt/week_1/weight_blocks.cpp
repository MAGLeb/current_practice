#include <iostream>

using namespace std;

int main() {
  u_int64_t result = 0;
  u_int64_t n, p, w, h, d;
  cin >> n >> p;

  while(n--) {
    cin >> w >> h >> d;
    result += w * h * d * p;
  }

  cout << result << endl;
}