#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b, c;
  bool found = false;

  for(a = 1; a < 1000; ++a){
    for(b = a+1; b < 1000; ++b){
      for(c = b+1; c < 1000; ++c){
        if(a + b + c == 1000) {
          if(pow(a, 2) + pow(b, 2) == pow(c, 2)) {
            found = true;
            break;
          }
        }
      }
      if(found) break;
    }
    if(found) break;
  }
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  cout << a * b * c << endl;
}