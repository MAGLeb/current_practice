#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, v;
  cin >> n;
  set<int> values;

  while(n--) {
    cin >> v;
    if(v == 0){
      continue;
    }
    values.insert(v);
  }
  cout << values.size() << endl;


}