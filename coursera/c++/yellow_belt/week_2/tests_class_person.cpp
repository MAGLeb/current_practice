#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T> ostream &operator<<(ostream &os, const vector<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (const auto &kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string &hint) { AssertEqual(b, true, hint); }

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string &test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception &e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

//class Person {
//public:
//  void ChangeFirstName(int year, const string &first_name) {
//    // добавить факт изменения имени на first_name в год year
//  }
//  void ChangeLastName(int year, const string &last_name) {
//    // добавить факт изменения фамилии на last_name в год year
//  }
//  string GetFullName(int year) {
//    // получить имя и фамилию по состоянию на конец года year
//  }
//
//private:
//  // приватные поля
//};

void TestFirstName() {
  Person person;

  AssertEqual(person.GetFullName(2000), "Incognito", "F1");

  person.ChangeFirstName(1999, "Gleb");
  AssertEqual(person.GetFullName(2000), "Gleb with unknown last name", "F2");
  AssertEqual(person.GetFullName(1998), "Incognito", "F3");

  person.ChangeFirstName(1999, "Igor");
  AssertEqual(person.GetFullName(1999), "Igor with unknown last name", "F4");
}

void TestSecondName() {
  Person person;

  AssertEqual(person.GetFullName(2000), "Incognito", "S1");

  person.ChangeLastName(1999, "Maksimov");
  AssertEqual(person.GetFullName(2000), "Maksimov with unknown first name", "S2");
  AssertEqual(person.GetFullName(1998), "Incognito","S3");

  person.ChangeLastName(1999, "MsSimof");
  AssertEqual(person.GetFullName(1999), "MsSimof with unknown first name","S4");
}

void TestFirstSecondName() {
  Person person;
  person.ChangeFirstName(1999, "Gleb");
  person.ChangeLastName(1999, "Maksimov");
  person.ChangeFirstName(2001, "Eugenio");
  person.ChangeLastName(2001, "MsSimof");
  person.ChangeFirstName(1995, "Aaron");
  person.ChangeLastName(1995, "Illuminatos");

  AssertEqual(person.GetFullName(1999), "Gleb Maksimov", "FS1");
  AssertEqual(person.GetFullName(1996), "Aaron Illuminatos", "FS2");
  AssertEqual(person.GetFullName(2001), "Eugenio MsSimof", "FS3");

  person.ChangeFirstName(1999, "Igor1");
  person.ChangeFirstName(1995, "Igor2");
  person.ChangeFirstName(2001, "Igor3");
  person.ChangeLastName(1999, "Maksimov1");
  person.ChangeLastName(1995, "Maksimov2");
  person.ChangeLastName(2001, "Maksimov3");

  AssertEqual(person.GetFullName(1999), "Igor1 Maksimov1", "FS4");
  AssertEqual(person.GetFullName(1996), "Igor2 Maksimov2", "FS5");
  AssertEqual(person.GetFullName(2001), "Igor3 Maksimov3", "FS6");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestFirstName, "TestFirstName");
  runner.RunTest(TestSecondName, "TestSecondName");
  runner.RunTest(TestFirstSecondName, "TestFirstSecondName");
  return 0;
}