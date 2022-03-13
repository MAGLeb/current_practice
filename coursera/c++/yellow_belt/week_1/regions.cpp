#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int FindMaxRepetitionCount(const vector<Region> &regions) {
  map<Region, int> results;
  int result = 0;

  for (const Region &region : regions) {
    result = max(result, ++results[region]);
  }
  return result;
}

auto FormatRegionToTuple(const Region &region) {
  return tie(region.std_name, region.parent_std_name, region.population,
             region.names);
}

bool operator<(const Region &lhs, const Region &rhs) {
  return FormatRegionToTuple(lhs) < FormatRegionToTuple(rhs);
}

int main() {
  cout
      << FindMaxRepetitionCount({
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
         })
      << endl;

  cout
      << FindMaxRepetitionCount({
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Russia",
              "Eurasia",
              {{Lang::DE, "Russland"},
               {Lang::FR, "Russie"},
               {Lang::IT, "Russia"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"},
               {Lang::FR, "Moscou deux"},
               {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Toulouse",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              89},
             {"Moscow",
              "Russia",
              {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
              31},
         })
      << endl;

  return 0;
}
