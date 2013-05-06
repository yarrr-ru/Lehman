#include <iostream>
#include <vector>

template < typename T >
class Dumb
{
  public:
    Dumb()
    {
    }

    void operator () (T a_num, std::vector < T > & a_res)
    {
      for(T i = 2; i * i <= a_num; ++i) {
        while(a_num % i == 0) {
          a_res.push_back(i);
          a_num /= i;
        }
      }
      if(a_num > 1)
        a_res.push_back(a_num);
    }
};
