#include "query.h"

using namespace std;

istream &operator>>(istream &is, Query &q) {
  string query_type;
  is >> query_type;
  q.stops.resize(0);

  if (query_type == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  } else if (query_type == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (query_type == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (query_type == "NEW_BUS") {
    q.type = QueryType::NewBus;
    int number_stops;
    is >> q.bus >> number_stops;
    while (number_stops--) {
      string stop;
      is >> stop;
      q.stops.push_back(stop);
    }
  }

  return is;
}