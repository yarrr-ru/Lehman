#include <iostream>
#include <cstdint>
#include <vector>

#include <boost/foreach.hpp>

#include "lehman.hpp"

int main() {
  // data type for numbers
  typedef uint64_t num_t;

  // create factorizer
  Lehman < num_t > factorizer;

  // read numbers
  num_t num;

  while(std::cin >> num) {
    std::vector < num_t > factors;

    // factorize
    factorizer(num, factors);

    // output
    std::cout << "Factors of " << num << ":";

    BOOST_FOREACH(const num_t& factor, factors)
      std::cout << " " << factor;

    std::cout << std::endl;
  }

  return 0;
}
