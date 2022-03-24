#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum class QueryType { NewBus, BusesForStop, StopsForBus, AllBuses };

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

ostream &operator<<(ostream &os, Query &q) {
  os << "Type: " << static_cast<int>(q.type) << " "
     << " bus: " << q.bus << " "
     << " stop: " << q.stop << endl;

  return os;
}

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

struct BusesForStopResponse {
  vector<string> buses;
};

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

struct StopsForBusResponse {
  vector<string> stops;
  map<string, vector<string>> stops_for_bus;
};

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

struct AllBusesResponse {
  vector<string> buses;
  map<string, vector<string>> stops_for_bus;
};

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

class BusManager {
private:
  map<string, vector<string>> buses_for_stop;
  map<string, vector<string>> stops_for_bus;
  map<string, vector<string>> all_buses;

public:
  void AddBus(const string &bus, const vector<string> &stops) {
    for (string stop : stops) {
      buses_for_stop[stop].push_back(bus);
      stops_for_bus[bus].push_back(stop);
    }
  }

  BusesForStopResponse GetBusesForStop(const string &stop) const {
    BusesForStopResponse result;
    if (buses_for_stop.find(stop) != buses_for_stop.end()) {
      result.buses = buses_for_stop.at(stop);
    }
    return result;
  }

  StopsForBusResponse GetStopsForBus(const string &bus) const {
    StopsForBusResponse result;
    if (stops_for_bus.find(bus) != stops_for_bus.end()) {
      for (auto &stop : stops_for_bus.at(bus)) {
        result.stops.push_back(stop);
        for (auto &other_bus : buses_for_stop.at(stop)) {
          if (other_bus != bus)
            result.stops_for_bus[stop].push_back(other_bus);
        }
      }
    }
    return result;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse result;
    for (auto &pair : stops_for_bus) {
      result.buses.push_back(pair.first);
    }
    sort(result.buses.begin(), result.buses.end());
    result.stops_for_bus = stops_for_bus;
    return result;
  }
};

void TestAddBuses() {
  BusManager bm;

  cout << bm.GetAllBuses() << endl;
  cout << bm.GetBusesForStop("Bolagoe") << endl;
  cout << bm.GetStopsForBus("32k") << endl;

  bm.AddBus("32", vector<string>({"Tolstopaltsevo", "Marushkino", "Vnukovo"}));
  cout << bm.GetAllBuses() << endl;
  bm.AddBus("32K", vector<string>({"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Smirnova"}));
  cout << bm.GetAllBuses() << endl;

//  bm.AddBus("950", vector<string>({"Ostashkino", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Smirnova"}));
//
//  cout << bm.GetAllBuses() << endl;
//  cout << bm.GetBusesForStop("Ostashkino") << endl;
//  cout << bm.GetBusesForStop("Peredelkino") << endl;
//  cout << bm.GetStopsForBus("66") << endl;
//  cout << bm.GetStopsForBus("66K") << endl;
//  cout << bm.GetStopsForBus("950") << endl;
//
//  cout << bm.GetAllBuses() << endl;
}

int main() {
//  TestAddBuses();
//  return 0;

  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;

    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}