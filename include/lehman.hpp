#include <iostream>
#include <vector>
#include <cassert>

namespace
{
  template < typename T, int P >
  struct power
  {
    static T pow(const T& a_base)
    {
      if((P & 1) == 0) {
        const T res = power < T, P / 2 > :: pow(a_base);
        return res * res;
      } else {
        return power < T, P - 1 > ::pow(a_base) * a_base;
      }
    }
  };

  template < typename T >
  struct power < T, 1 >
  {
    static T pow(const T& a_base)
    {
      return a_base;
    }
  };

  template < typename T, int P >
  T root(const T& a_num)
  {
    assert(a_num >= 0);

    T l = 0, r = a_num + 1;

    while(r - l > 1) {
      T m = (l + r) / 2, m_powed = power < T, P > :: pow(m);

      if(m_powed <= a_num)
        l = m;
      else
        r = m;
    }

    return l;
  }

  template < typename T >
  bool is_perfect_square(const T& a_num)
  {
    assert(a_num >= 0);

    const T r = root < T, 2 > (a_num);
    return r * r == a_num;
  }

  template < typename T >
  T gcd(const T& a, const T& b)
  {
    assert(a >= 0 && b >= 0);

    if(b == 0)
      return a;

    return gcd(b, a % b);
  }
}

template < typename T >
class Lehman
{
  public:
    void first_step(const T& a_num, std::vector < T > & a_res)
    {
      const T limit = root < T, 3 > (a_num);
    
      for(T i = 2; i <= limit; ++i) {
        if(a_num % i == 0) {
          a_res.push_back(i);
          a_res.push_back(a_num / i);
          return;
        }
      }
    }

    void second_step(T& n, std::vector < T > & a_res)
    {
      const T k_limit = root < T, 3 > (n);
 
      for(T k = 1; k <= k_limit; ++k) {
        const T d_limit = (root < T, 6 > (n) / (T(4) * root < T, 2 > (k))) + 1;
      
        const T v = T(4) * k * n;

        for(T d = 0, A = root < T, 2 > (v), AA = A * A; d <= d_limit; ++d, AA += T(2) * A + T(1), ++A) {
          const T c = AA - v;

          if(c >= 0 && is_perfect_square < T > (c)) {
            const T B = root < T, 2 > (A * A - v);

            if((A * A) % n == (B * B) % n) {
              assert(A > B);

              const T g = gcd < T > (A - B, n);

              if(T(1) < g && g < n) {
                assert(n % g == 0);

                a_res.push_back(g);
                a_res.push_back(n / g);
                return;
              }
            }
          }
        }
      }

      a_res.push_back(n);
    }

    void operator () (T a_num, std::vector < T > & a_res)
    {
      assert(a_num > 1);

      first_step(a_num, a_res);
      
      if(a_res.size() == 0)
        second_step(a_num, a_res);
    }
};
