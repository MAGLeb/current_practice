#include <iostream>

using namespace std;

#include "responses.h"

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
  if (r.buses.empty())
    os << "No stop";
  else {
    bool first = true;
    for (auto &bus : r.buses) {
      if (first) {
        first = false;
        os << bus;
      } else
        os << " " << bus;
    }
  }
  return os;
}

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
  if (r.stops.empty())
    os << "No bus";
  else {
    for (auto &stop : r.stops) {
      if (r.stops_for_bus.find(stop) == r.stops_for_bus.end())
        os << "Stop " << stop << ": no interchange" << endl;
      else {
        os << "Stop " << stop << ":";
        for (auto &bus : r.stops_for_bus.at(stop)) {
          os << " " << bus;
        }
        os << endl;
      }
    }
  }
  return os;
}

ostream &operator<<(ostream &os, const AllBusesResponse &r) {
  if (r.buses.empty())
    os << "No buses";
  else {
    for (auto &bus : r.buses) {
      os << "Bus " << bus << ":";
      for (auto &stop : r.stops_for_bus.at(bus))
        os << " " << stop;
      os << endl;
    }
  }

  return os;
}