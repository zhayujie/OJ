#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  double Power(double base, int exponent) {
    if (base == 0.0) return 0.0;
    if (exponent == 0)  return 1;
    if (exponent == 1)  return base;
    if (exponent == -1)  return 1.0 / base;
    double result = Power(base, exponent/2);
    if ((exponent & 1) == 0) {  // 偶数
      return result * result;
    } else {                    // 奇数，注意奇数负数不能用移位代替除以2
      return result * result * (exponent > 0 ? base : 1.0/base);
    }
  }
};

int main(void) {
  Solution soulution;
  cout << soulution.Power(2, -3) << endl;
  return 0;
}
