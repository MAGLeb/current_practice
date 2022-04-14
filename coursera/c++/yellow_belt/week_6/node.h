#pragma once

#include "date.h"

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum class LogicalOperation { Or, And };

class Node {
public:
  Node();
  virtual bool Evaluate(const Date &date, const string &event) = 0;
};

class EmptyNode : public Node {
public:
  EmptyNode();
  bool Evaluate(const Date &date, const string &event) override;
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(const Comparison &cmp, const Date &date);
  bool Evaluate(const Date &date, const string &event) override;

private:
  const Comparison cmp_;
  const Date date_;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(const Comparison &cmp, const string &event);
  bool Evaluate(const Date &date, const string &event) override;

private:
  Comparison cmp_;
  string event_;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation &operation,
                       const shared_ptr<Node> &left,
                       const shared_ptr<Node> &right);
  bool Evaluate(const Date &date, const string &event) override;

private:
  LogicalOperation operation_;
  shared_ptr<Node> right_;
  shared_ptr<Node> left_;
};