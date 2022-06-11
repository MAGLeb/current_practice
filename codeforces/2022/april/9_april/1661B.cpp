#include <bits/stdc++.h>

using namespace std;

int DELIMITER = 32768;

int find_mod(int x, int result, vector<int> &m) {
  if(result == 15)
    return result;

  x %= DELIMITER;
  if (x == 0)
    return result;
  if(m[x] != 0)
    return m[x] + result;

  return min(find_mod(x * 2, result + 1, m), find_mod(x + 1, result + 1, m));
}

int main() {
  int n;
  cin >> n;
  vector<int> memory(DELIMITER + 1, 0);

  while (n--) {
    int w;
    cin >> w;
    int counter = find_mod(w, 0, memory);
    cout << counter << endl;
    memory[w] = counter;
  }
}