#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  int NumberOf1(int n) {
    int count = 0;
    // int flag = 1;
    // while (flag) {
    //   if (n & flag) {
    //     count++;
    //   }
    //   flag = flag << 1;
    // }
    while (n) {
      n = (n-1) & n;
      count++;
    }

    return count;
  }
};

int main(void) {
  Solution soulution;
  return 0;
}
