#include <iostream>

using namespace std;

int MAX_VALUE = 4000000;

int main() {
  long result = 0;
  int first = 1;
  int second = 2;
  int tmp;

  while(second < MAX_VALUE) {
    if(second % 2 == 0) result += second;
    tmp = second;
    second += first;
    first = tmp;
  }

  cout << result << endl;
}