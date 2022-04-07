#include <bits/stdc++.h>
#include <iterator>

using namespace std;

bool comparator_pair(const pair<int, string> &f, const pair<int, string> &s) {
  return f.first < s.first;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first.insert({year, first_name});
  }
  void ChangeLastName(int year, const string& last_name) {
    second.insert({year, last_name});
  }

  string GetCurrentName(const map<int, string> &o, const int &year) const {
    if(o.empty())
      return "";

    auto it = o.lower_bound(year);
    if(it->first == year)
      return it->second;

    if(it == o.begin())
      return "";
    return prev(it)->second;
  };

  string GetFullName(int year) {
    string name = GetCurrentName(first, year);
    string surname = GetCurrentName(second, year);

    if(name.empty() && surname.empty())
      return "Incognito";
    else if(name.empty())
      return surname + " with unknown first name";
    else if(surname.empty())
      return name + " with unknown last name";
    else
      return name + ' ' + surname;
  };

private:
  map<int, string> first;
  map<int, string> second;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
