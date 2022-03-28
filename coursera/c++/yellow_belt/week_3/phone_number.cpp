#include "phone_number.h"
#include <bits/stdc++.h>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
  istringstream is(international_number);

  char sign = is.get();
  getline(is, country_code_, '-');
  getline(is, city_code_, '-');
  getline(is, local_number_);

  if(sign != '+' || !country_code_.size() || city_code_.empty() || !local_number_.size())
    throw invalid_argument("Invalid number");
}

string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
string PhoneNumber::GetCityCode() const {
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
  return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

void TestNumber(PhoneNumber phone) {
  cout << phone.GetCountryCode() << endl;
  cout << phone.GetCityCode() << endl;
  cout << phone.GetLocalNumber() << endl;
  cout << phone.GetInternationalNumber() << endl;
}

int main() {}