#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  double Power(double base, int exponent) {
    if (base == 0.0)  return 0.0;
    if (exponent == 0) {
      return 1;
    }
    else if (exponent > 0) {
      return powerCore(base, exponent);
    } else {
      return 1.0 / powerCore(base, -exponent);
    }
  }
  double powerCore(double base, int exp) {
    double res = 1.0;
    for (int i = 0; i < exp; i++) {
      res *= base;
    }
    return res;
  }
};

int main(void) {
  Solution soulution;
  return 0;
}
