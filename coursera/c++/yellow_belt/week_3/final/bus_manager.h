#pragma once

#include <vector>
#include <string>
#include <map>

using namespace std;

#include "responses.h"

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops);
  BusesForStopResponse GetBusesForStop(const string& stop) const;
  StopsForBusResponse GetStopsForBus(const string& bus) const;
  AllBusesResponse GetAllBuses() const;

private:
  map<string, vector<string>> buses_for_stop;
  map<string, vector<string>> stops_for_bus;
  map<string, vector<string>> all_buses;
};