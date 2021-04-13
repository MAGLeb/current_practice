#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, result_1, result_2, d;
    cin >> a >> b >> c;
    d = sqrt(pow(b, 2) - 4*a*c);
    result_1 = (-b-d)/(2*a);
    result_2 = (-b+d)/(2*a);

    if(isnan(d)) {
        return 0;
    }
    if(a == 0) {
        if(b == 0) {
            return 0;
        }
        result_1 = -c / b;
        cout << result_1;
        return 0;
    }
    if(result_2 == result_1) {
        cout << result_2;
    } else {
        cout << result_1 << ' ' << result_2;
    }
    return 0;
}
