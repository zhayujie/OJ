#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
      if (threshold <= 0)     return 0;
      bool visited[rows*cols];
      memset(visited, 0, rows*cols);
      int count = 0;
      movingCount(threshold, rows, cols, 0, 0, visited, count);
      return count;
    }

    void movingCount(int threshold, int rows, int cols, int i, int j, bool* visited, int &count)
    {
      if (i == rows || i < 0 || j == cols || j < 0 || visited[cols*i+j] || getCount(i)+getCount(j) > threshold) {   
        return;
      }
      visited[cols*i+j] = true;
      count++;
      movingCount(threshold, rows, cols, i-1, j, visited, count);
      movingCount(threshold, rows, cols, i, j-1, visited, count);
      movingCount(threshold, rows, cols, i+1, j, visited, count);
      movingCount(threshold, rows, cols, i, j+1, visited, count);
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
