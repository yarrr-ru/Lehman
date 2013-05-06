#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdint>
#include <vector>
#include <algorithm>

#include <boost/random/mersenne_twister.hpp>

#include "lehman.hpp"
#include "dumb.hpp"

template < typename T >
std::string vector_to_string(const std::vector < T > & a_v)
{
  std::stringstream res;
  std::copy(a_v.begin(), a_v.end(), std::ostream_iterator < T > (res, " "));
  return res.str();
}

int main() {
  // data type for numbers
  typedef uint64_t num_t;

  // create factorizer
  Lehman < num_t > factorizer;

  // read numbers
  num_t num;

  // stress test
  Dumb < num_t > factorizer_dumb;
  boost::random::mt19937_64 rand;

  while(true) {
    num = rand();
    std::vector < num_t > factors, dumb_factors;
  
    factorizer(num, factors);
    factorizer_dumb(num, dumb_factors);

    std::sort(factors.begin(), factors.end());
    std::sort(dumb_factors.begin(), dumb_factors.end());

    if(factors != dumb_factors) {
      std::cerr << "Stress test failed for " << num << std::endl;
      std::cerr << "Factors: " << vector_to_string(dumb_factors) << std::endl;
      std::cerr << "Our output: " << vector_to_string(factors) << std::endl;
      return 1;
    }
  }

  while(std::cin >> num) {
    std::vector < num_t > factors;

    // factorize
    factorizer(num, factors);

    // output
    std::cout << "Factors of " << num << ": " << vector_to_string(factors) << std::endl;
  }

  return 0;
}
