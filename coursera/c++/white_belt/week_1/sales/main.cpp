#include <iostream>

using namespace std;

int main() {
    double cost, a, b, x, y;
    cin >> cost >> a >> b >> x >> y;

    if(cost > b) {
        cout << cost * ((100 - y) * 0.01);
    } else if(cost > a) {
        cout << cost * ((100 - x) * 0.01);
    } else {
        cout << cost;
    }

    return 0;

}
