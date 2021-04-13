#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int n, m;
    input >> n >> m;

    for(int i = 0; i < n; ++ i) {
        int value;
        for(int j = 0; j < m - 1; ++ j) {
            input >> value;
            input.ignore(1);
            cout << setw(10) << value << ' ';
        }
        input >> value;
        cout << setw(10) << value;
        if(i != n - 1) {
            cout << endl;
        }
    }
    return 0;
}