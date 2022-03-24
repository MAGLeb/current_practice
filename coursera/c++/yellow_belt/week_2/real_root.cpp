#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
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

int GetDistinctRealRootCount(double a, double b, double c);

void TestQuadraticEquation() {
  AssertEqual(GetDistinctRealRootCount(1, 2, 0), 2, "Q1");
  AssertEqual(GetDistinctRealRootCount(1, -2, 0), 2, "Q2");
  AssertEqual(GetDistinctRealRootCount(-1, -2, 0), 2, "Q3");
  AssertEqual(GetDistinctRealRootCount(-1, 2, 0), 2, "Q8");
  AssertEqual(GetDistinctRealRootCount(1, 0, 4), 0, "Q4");
  AssertEqual(GetDistinctRealRootCount(1, 0, -4), 2, "Q5");
  AssertEqual(GetDistinctRealRootCount(-1, 0, 4), 2, "Q6");
  AssertEqual(GetDistinctRealRootCount(-1, 0, -4), 0, "Q7");
  AssertEqual(GetDistinctRealRootCount(-7, 3, -13), 0, "Q9");
}

void TestLinearEquation() {
  AssertEqual(GetDistinctRealRootCount(0, 20, 10), 1, "L1");
  AssertEqual(GetDistinctRealRootCount(0, 0, 10), 0, "L2");
  AssertEqual(GetDistinctRealRootCount(0, 20, 0), 1, "L3");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestLinearEquation, "TestLinearEquation");
  runner.RunTest(TestQuadraticEquation, "TestQuadraticEquation");

  return 0;
}