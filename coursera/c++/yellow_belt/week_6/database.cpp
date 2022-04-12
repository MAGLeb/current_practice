#include <iostream>

#include "database.h"
using namespace std;

void DataBase::Add(const Date &date, const string &event) {
  auto it = find(begin(date_event_mapper), end(date_event_mapper));
  if(it != end(date_event_mapper)) {
    if(date.GetDate() == *it.first);
  }


}