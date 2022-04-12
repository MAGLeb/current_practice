#pragma once

#include "date.h"

#include <iostream>
using namespace std;

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual;
};

class Node {
public:
  int Evaluate(const Date &date, const string &event) ;
};

class EmptyNode : public Node {

};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(const Comparison &cmp, const Date &date);
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(const Comparison &cmp, const string &event);
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation &operation, const Node &left, const Node &right);
};