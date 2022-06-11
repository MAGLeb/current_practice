#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  while(n--) {
    int m_1 = 0;
    int m_2 = 0;
    int inter = 0;
    int k;
    cin >> k;

    while(k--) {
      cin >> inter;
      if(inter > m_2 || inter > m_1) {
        m_2 = max(m_1, m_2);
        m_1 = inter;
      }
    }

    if(abs(m_2 - m_1) < 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}