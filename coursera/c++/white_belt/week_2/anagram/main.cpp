#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        string first, second;
        cin >> first >> second;

        if (first.size() == second.size()) {
            map<char, int> m_first, m_second;
            for (int j = 0; j < first.size(); ++ j) {
                m_first[first[j]]++;
                m_second[second[j]]++;
            }
            if (m_first == m_second) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
