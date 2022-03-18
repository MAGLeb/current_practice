#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long> primes;

  for(long i = 3; i < 57000000; i = i + 2) {
    if(primes.size() == 10000) break;
    bool is_prime = true;
    for(long number : primes) {
      if(i % number == 0) {
        is_prime = false;
        break;
      }
    }

    if(is_prime) primes.push_back(i);
  }

  cout << *(primes.end() - 1) << endl;
}