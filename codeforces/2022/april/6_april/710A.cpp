#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  char h, v;
  cin >> h >> v;

  vector<char> edges = {'a', 'h', '1', '8'};

  if(find(begin(edges), end(edges), h) != end(edges) && find(begin(edges), end(edges), v) != end(edges))
    cout << 3 << endl;
  else if (find(begin(edges), end(edges), h) != end(edges) || find(begin(edges), end(edges), v) != end(edges))
    cout << 5 << endl;
  else
    cout << 8 << endl;
}