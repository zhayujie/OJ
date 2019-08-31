#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold <= 0)     return 1;
        bool visited[rows*cols];
        bool counted[rows*cols];
        memset(visited, 0, rows*cols);
        memset(counted, 0, rows*cols);
    }

    int getCount(int num) {
      int count = 0;
      while (num > 0) {
        count += num % 10;
        num /= 10;
      }
      return count;
    }
};

int main(void) {
  Solution soulution;

  return 0;
}
