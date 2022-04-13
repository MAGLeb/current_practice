#pragma once

#include "date.h"

#include <iostream>
using namespace std;

enum class Comparison {
  Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual;
};

enum class LogicalOperation { Or, And; };

class Node {
public:
  virtual  Evaluate(const Date &date, const string &event);
};

class EmptyNode : public Node {};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(const Comparison &cmp, const Date &date)
      : cmp_(cmp), date_(date);
  bool Evaluate(const Date &date, const string &event) override;

private:
  Comparison cmp_;
  Date date_;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(const Comparison &cmp, const string &event)
      : cmp_(cmp), event_(event);
  bool Evaluate(const Date &date, const string &event) override;

private:
  Comparison cmp_;
  string event_;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation &operation, const Node &left,
                       const Node &right)
      : operation_(operation), left_(left), right_(right);
  bool Evaluate(const Date &date, const string &event) override;

private:
  LogicalOperation operation_;
  Node right_;
  Node left_;
};