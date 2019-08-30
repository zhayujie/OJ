#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
      // if (n == 0)   return 0;
      // if (n == 1)   return 1;
      // return Fibonacci(n-1) + Fibonacci(n-2);
      int v1 = 0, v2 = 1, vn = 0;
      if (n == 0)     vn = v1;
      if (n == 1)     vn = v2;
      for (int i = 2; i <= n; i++) {
        vn = v1 + v2;
        v1 = v2;
        v2 = vn;
      }
      return vn;
    }
};

int main(void) {
  Solution soulution;

  return 0;
}
