#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
  int n;
  string letters;
  cin >> n;

  while(n != 0) {
    cin >> letters;
    set<char> result;
    int i = 0;

    while(i < letters.size()) {
      if(letters[i] == letters[i + 1])
        i += 2;
      else {
        result.insert(letters[i]);
        i += 1;
      }
    }

    for(auto l : result)
      cout << l;
    cout << endl;

    --n;
  }
}