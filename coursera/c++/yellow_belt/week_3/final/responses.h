#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct BusesForStopResponse {
  vector<string> buses;
};

struct AllBusesResponse {
  vector<string> buses;
  map<string, vector<string>> stops_for_bus;
};

struct StopsForBusResponse {
  vector<string> stops;
  map<string, vector<string>> stops_for_bus;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r);

ostream &operator<<(ostream &os, const StopsForBusResponse &r);

ostream &operator<<(ostream &os, const AllBusesResponse &r);