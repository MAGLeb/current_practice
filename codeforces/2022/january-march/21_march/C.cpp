#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  char tmp;
  string number;
  cin >> n;

  while(n != 0) {
    cin >> number;
    for(int i = 0; i < number.size() - 1; ++i) {
      char first = number[i];
      char second = number[i + 1];

//      cout << "TEST_1: " << (int)(first) + (int)(second) - 96 % 2 << " " << number[i] << " " << number[i + 1] << endl;

      if(number[i] > number[i + 1] && ((int)(first) + (int)(second)) % 2 == 1) {
        tmp = number[i];
        number[i] = number[i + 1];
        number[i + 1] = tmp;
      }

    }
    for(int i = number.size() - 1; i > 0; --i) {
      char first = number[i];
      char second = number[i - 1];

      if(number[i] < number[i - 1] && ((int)(first) + (int)(second)) % 2 == 1) {
        tmp = number[i];
        number[i] = number[i - 1];
        number[i - 1] = tmp;
      }

    }

    cout << number << endl;
    --n;
  }


}