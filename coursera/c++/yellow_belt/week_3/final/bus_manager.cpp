#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#include "bus_manager.h"

void BusManager::AddBus(const string &bus, const vector<string> &stops) {
  for (string stop : stops) {
    buses_for_stop[stop].push_back(bus);
    stops_for_bus[bus].push_back(stop);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const {
  BusesForStopResponse result;
  if (buses_for_stop.find(stop) != buses_for_stop.end()) {
    result.buses = buses_for_stop.at(stop);
  }
  return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
  AllBusesResponse result;
  for (auto &pair : stops_for_bus) {
    result.buses.push_back(pair.first);
  }
  sort(result.buses.begin(), result.buses.end());
  result.stops_for_bus = stops_for_bus;
  return result;
}
