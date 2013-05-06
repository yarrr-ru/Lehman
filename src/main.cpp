#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cassert>

#include <boost/random/mersenne_twister.hpp>

#include "BigIntegerLibrary.hh"

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
  typedef BigInteger num_t;

  // create factorizer
  Lehman < num_t > factorizer;

  // read numbers
  num_t num;
  std::string num_str;

  // stress test
  /*Dumb < num_t > factorizer_dumb;
  boost::random::mt19937 rand;

  while(true) {
    num = (rand() + 2);
    std::vector < num_t > factors, dumb_factors;

    factorizer(num, factors);
    factorizer_dumb(num, dumb_factors);

    assert(factors.size() >= 1);

    std::sort(factors.begin(), factors.end());
    std::sort(dumb_factors.begin(), dumb_factors.end());

    if((factors.size() == 1) == (dumb_factors.size() == 1)) {
      std::cout << "Stress test is OK for " << num << std::endl;
    } else {
      std::cerr << "Stress test failed for " << num << std::endl;
      std::cerr << "Factors: " << vector_to_string(dumb_factors) << std::endl;
      std::cerr << "Our output: " << vector_to_string(factors) << std::endl;
      return 1;
    }
  }*/

  while(std::cin >> num_str) {
    // HELLO CONSTRUCTORS
    num = stringToBigInteger(num_str);

    assert(num > 1);
    
    std::vector < num_t > factors;

    // factorize
    factorizer(num, factors);

    // output
    // 1 (prime) or 2 (composite) factors
    std::cout << "Factors of " << num << ": " << vector_to_string(factors) << std::endl;
  }

  return 0;
}
