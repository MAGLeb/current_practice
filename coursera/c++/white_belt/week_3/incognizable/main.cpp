#include <iostream>

class Incognizable {
public:
    Incognizable() {
        first = 0;
        second = 0;
    }
    Incognizable(const int& x) {
        first = x;
        second = 0;
    }
    Incognizable(const int& x, const int& y) {
        first = x;
        second = y;
    }

private:
    int first;
    int second;
};

//int main() {
//    Incognizable a;
//    Incognizable b = {};
//    Incognizable c = {0};
//    Incognizable d = {0, 1};
//    return 0;
//}