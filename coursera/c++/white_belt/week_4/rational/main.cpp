#include <iostream>
#include <numeric>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

bool is_number(const string& s) {
    bool sign = s[0] == '-';
    auto it = s.begin() + sign;
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();

}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        if(new_denominator == 0) throw invalid_argument("Invalid argument");
        int nod = gcd(new_numerator, new_denominator);
        new_numerator = new_numerator / nod;
        new_denominator = new_denominator / nod;

        if(new_numerator * new_denominator > 0) {
            numerator = abs(new_numerator);
            denominator = abs(new_denominator);
        } else if(new_numerator * new_denominator < 0) {
            numerator = -abs(new_numerator);
            denominator = abs(new_denominator);
        } else {
            numerator = 0;
            denominator = 1;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator == (const Rational& first, const Rational& second) {
    if(first.Numerator() == second.Numerator()) {
        return first.Denominator() == second.Denominator();
    }
    return false;
}

Rational operator + (const Rational& first, const Rational& second) {
    int numerator = first.Numerator() * second.Denominator() + second.Numerator() * first.Denominator();
    int denominator = first.Denominator() * second.Denominator();
    return {numerator, denominator};
}

Rational operator - (const Rational& first, const Rational& second) {
    int numerator = first.Numerator() * second.Denominator() - second.Numerator() * first.Denominator();
    int denominator = first.Denominator() * second.Denominator();
    return {numerator, denominator};
}

Rational operator * (const Rational& first, const Rational& second) {
    int numerator = first.Numerator() * second.Numerator();
    int denominator = first.Denominator() * second.Denominator();
    return {numerator, denominator};
}

Rational operator / (const Rational& first, const Rational& second) {
    int numerator = first.Numerator() * second.Denominator();
    int denominator = first.Denominator() * second.Numerator();
    if(denominator == 0) throw domain_error("Division by zero");
    return {numerator, denominator};
}

istream& operator >> (istream& input, Rational& number) {
    int numerator, denominator;
    char slash;
    if(input) {
        input >> numerator >> slash >> denominator;
        if(slash == '/') {
            number = Rational(numerator, denominator);
        }
        return input;
    }
}

ostream& operator << (ostream& output, const Rational& number) {
    output << number.Numerator() << '/' << number.Denominator();
    return output;
}

bool operator < (const Rational& left, const Rational& right) {
    int first_value = left.Numerator() * right.Denominator();
    int second_value = right.Numerator() * left.Denominator();
    return first_value < second_value;
}

//int main() {
//    Rational first, second;
//    char operation;
//
//    try {
//        cin >> first;
//        cin >> operation;
//        cin >> second;
//        if(operation == '+') {
//            cout << first + second << endl;
//        } else if(operation == '-') {
//            cout << first - second << endl;
//        } else if(operation == '/') {
//            cout << first / second << endl;
//        } else {
//            cout << first * second << endl;
//        }
//    } catch (const exception& ex) {
//        cout << ex.what() << endl;
//    }
//}
