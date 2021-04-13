#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public:
    ReversibleString() = default;
    ReversibleString(const string& s) {
        str = s;
    }

    void Reverse() {
        string reversed_string;
        int left = 0, right = str.size() - 1;
        while(left < right) {
            char left_letter = str[left], right_letter = str[right];
            str[left] = right_letter;
            str[right] = left_letter;
            left ++;
            right --;
        }
    }

    string ToString() const {
        return str;
    }

private:
    string str;
};

//int main() {
//    ReversibleString s("live");
//    s.Reverse();
//    cout << s.ToString() << endl;
//
//    s.Reverse();
//    const ReversibleString& s_ref = s;
//    string tmp = s_ref.ToString();
//    cout << tmp << endl;
//
//    ReversibleString empty;
//    cout << '"' << empty.ToString() << '"' << endl;
//
//    return 0;
//}