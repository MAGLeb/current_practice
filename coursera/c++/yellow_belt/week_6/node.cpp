#include "node.h"

#include "date.h"
#include <bits/stdc++.h>

using namespace std;

Node::Node() {}

EmptyNode::EmptyNode() : Node() {}

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date)
    : Node(), cmp_(cmp), date_(date) {}

EventComparisonNode::EventComparisonNode(const Comparison &cmp,
                                         const string &event)
    : Node(), cmp_(cmp), event_(event) {}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &operation,
                                           const shared_ptr<Node> &left,
                                           const shared_ptr<Node> &right)
    : Node(), operation_(operation), left_(left), right_(right) {}

bool EmptyNode::Evaluate(const Date &date, const string &event) {
  return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) {
  if (cmp_ == Comparison::Equal) {
    return date == date_;
  } else if (cmp_ == Comparison::NotEqual) {
    return date != date_;
  } else if (cmp_ == Comparison::Greater) {
    return date > date_;
  } else if (cmp_ == Comparison::GreaterOrEqual) {
    return date >= date_;
  } else if (cmp_ == Comparison::Less) {
    return date < date_;
  } else if (cmp_ == Comparison::LessOrEqual) {
    return date <= date_;
  } else {
    throw invalid_argument("No comparison sign!");
  }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) {
  if (cmp_ == Comparison::Equal) {
    return event == event_;
  } else if (cmp_ == Comparison::NotEqual) {
    return event != event_;
  } else if (cmp_ == Comparison::Greater) {
    return event > event_;
  } else if (cmp_ == Comparison::GreaterOrEqual) {
    return event >= event_;
  } else if (cmp_ == Comparison::Less) {
    return event < event_;
  } else if (cmp_ == Comparison::LessOrEqual) {
    return event <= event_;
  } else {
    throw invalid_argument("No comparison sign!");
  }
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) {
  if (operation_ == LogicalOperation::And) {
    return right_->Evaluate(date, event) && left_->Evaluate(date, event);
  } else if (operation_ == LogicalOperation::Or) {
    return right_->Evaluate(date, event) || left_->Evaluate(date, event);
  } else {
    throw invalid_argument("No comparison sign!");
  }
}