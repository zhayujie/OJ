#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> res;
    vector<int> printMatrix(vector<vector<int> > matrix) {
      int rows = matrix.size();
      if (rows == 0)  return res;
      int cols = matrix[0].size();
      int start = 0;
      while (rows > start * 2 && cols > start * 2) {
        walk(matrix, rows, cols, start);
        start++;
      }
      return res;
    }

    void walk(vector<vector<int> > matrix, int rows, int cols, int start) {
      int endRow = rows - start - 1;
      int endCol = cols - start - 1; 
      
      // 向右走
      for (int i = start; i <= endCol; i++) {
        res.push_back(matrix[start][i]);
      }
      if (start+1 > endRow)   return;

      // 向下走
      for (int i = start+1; i <= endRow; i++) {
        res.push_back(matrix[i][endCol]);
      }
      if (endCol - 1 < start)  return;

      // 向左走
      for (int i = endCol-1; i >= start; i--) {
        res.push_back(matrix[endRow][i]);
      }

      // 向上走
      for (int i = endRow-1; i > start; i--) {
        res.push_back(matrix[i][start]);
      }
    }
};

int main(void) {
  Solution soulution;
  vector<vector<int> > matrix(4, vector<int>(4, 0));
  int t = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = ++t;
      // cout <<"matrix " << matrix[i][j] << endl;
    }
  }
  vector<int> vec = soulution.printMatrix(matrix);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }

  return 0;
}
