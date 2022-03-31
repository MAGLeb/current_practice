#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum class Gender { FEMALE, MALE };

struct Person {
  int age;          // возраст
  Gender gender;    // пол
  bool is_employed; // имеет ли работу
};

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person &lhs, const Person &rhs) { return lhs.age < rhs.age; });
  return middle->age;
}

void PrintStats(vector<Person> persons) {
  auto it_male =
      partition(begin(persons), end(persons), [](const Person &person) {
        return person.gender == Gender::MALE;
      });

  auto it_emp_female =
      partition(it_male, end(persons),
                [](const Person &person) { return person.is_employed; });

  auto it_emp_male =
      partition(begin(persons), it_male,
                [](const Person &person) { return person.is_employed; });

  cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons))
       << endl;
  cout << "Median age for females = " << ComputeMedianAge(it_male, end(persons)) << endl;
  cout << "Median age for males = " << ComputeMedianAge(begin(persons), it_male) << endl;
  cout << "Median age for employed females = " << ComputeMedianAge(it_male, it_emp_female) << endl;
  cout << "Median age for unemployed females = " << ComputeMedianAge(it_emp_female, end(persons)) << endl;
  cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), it_emp_male) << endl;
  cout << "Median age for unemployed males = " << ComputeMedianAge(it_emp_male, it_male) << endl;
}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},   {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},    {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false}, {78, Gender::MALE, false},
      {10, Gender::FEMALE, false}, {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}