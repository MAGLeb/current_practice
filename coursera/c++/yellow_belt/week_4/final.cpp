#include <bits/stdc++.h>

using namespace std;

void PrintExpressionWithout(const string &initial,
                            const vector<char> &operations,
                            const vector<string> &numbers,
                            const int &initial_brackets) {
  char prev_operation = ' ';
  char operation = ' ';
  int k = operations.size();

  cout << string(initial_brackets, '(') << initial;

  for (int i = 0; i < k; ++i) {
    operation = operations[i];

    if ((prev_operation == '+' || prev_operation == '-') &&
        (operation == '*' || operation == '/')) {
      cout << ')';
    }
    cout << ' ' << operation << ' ' << numbers[i];
    prev_operation = operation;
  }

  cout << endl;
}

void PrintExpression(const string &initial, const vector<char> &operations,
                     const vector<string> &numbers) {
  int k = operations.size();
  cout << string(k, '(') << initial << string(min(k, 1), ')');

  for (int i = 0; i < k; ++i) {
    cout << ' ' << operations[i] << ' ' << numbers[i];
    if (i != k - 1)
      cout << ')';
  }
  cout << endl;
}

int main() {
  int initial, number, k;
  int counter = 0;
  char operation;
  char prev_operation = ' ';
  cin >> initial >> k;
  vector<char> operations(k);
  vector<string> numbers(k);

  for (int i = 0; i < k; ++i) {
    cin >> operation >> number;
    operations[i] = operation;
    numbers[i] = to_string(number);

    if ((prev_operation == '+' || prev_operation == '-') &&
        (operation == '*' || operation == '/')) {
      counter++;
    }
    prev_operation = operation;
  }

  PrintExpression(to_string(initial), operations, numbers);
//  PrintExpressionWithout(to_string(initial), operations, numbers, counter);
}