#include <iostream>

using namespace std;

bool is_palindromic(int number) {
  string string_number = to_string(number);

  auto start = string_number.begin();
  auto end = string_number.end() - 1;
  while(start < end) {
    if(*start != *end) return false;
    ++start;
    --end;
  }
  return true;
}

int main() {
  int result;

  for(int i = 999; i > 0; --i) {
    for(int j = 999; j > 0; --j) {
      if(is_palindromic(i * j)) {
        result = max(i * j, result);
        break;
      }
    }
  }

  cout << result << endl;
}