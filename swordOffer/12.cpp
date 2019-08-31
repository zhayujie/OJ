#include <iostream>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
      if (strlen(matrix) == 0 || strlen(str) == 0)    return false;
      bool vis[rows * cols];
      memset(vis, 0, rows * cols);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          bool flag = hasPathCore(matrix, rows, cols, i, j, str, 0, vis);
          if (flag)   return true;
        }
      }
      return false;
    }

    bool hasPathCore(char* matrix, int rows, int cols, int i, int j, char* str, int index, bool* visited)
    {
      if (index == strlen(str))   return true;
      if (i < 0 || j < 0 || visited[i*cols+j])   return false;
      bool flag = false;
      if (matrix[i*cols+j] == str[index]) {
        visited[i*cols+j] = true;   // 标记走过的路
        flag = hasPathCore(matrix, rows, cols, i-1, j, str, index+1, visited) || hasPathCore(matrix, rows, cols, i, j-1, str, index+1, visited) || 
              hasPathCore(matrix, rows, cols, i+1, j, str, index+1, visited) || hasPathCore(matrix, rows, cols, i, j+1, str, index+1, visited);
        if (!flag) {
          // 回溯，将访问标志重置
          visited[i*cols+j] = false;
        }
      }
      return flag;
    }
};

int main(void) {
  Solution soulution;

  return 0;
}
