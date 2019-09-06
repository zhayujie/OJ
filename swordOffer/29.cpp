#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int curRow;
    int curCol;
    int count;
    vector<int> res;
    vector<int> printMatrix(vector<vector<int> > matrix) {
      curRow = 0;
      curCol = 0;
      count = 0;
      int rows = matrix.size();
      int cols = matrix[0].size();
      bool visited[rows * cols];
      memset(visited, false, rows * cols);

      while (true) {
        int res1 = walk(matrix, visited, rows, cols, curRow, curCol, 0, 1);
        int res2 = walk(matrix, visited, rows, cols, curRow, curCol, 1, 1);
        int res3 = walk(matrix, visited, rows, cols, curRow, curCol, 2, 1);
        int res4 = walk(matrix, visited, rows, cols, curRow, curCol, 3, 1);
        if (count == rows * cols) {
          break;
        }
      }
      return res;
    }

    int walk(vector<vector<int> > matrix, bool *visited, int rows, int cols, int i, int j, int direction, int type) {
      if (i < 0 || i >= rows || j < 0 || j >= cols || (type != 1 && visited[i*cols+j])) {
        return 0;
      }
      if (!visited[i*cols+j]) {
        count++;
        visited[i*cols+j] = true;
        curRow = i;
        curCol = j;
        res.push_back(matrix[i][j]);
      }
      if (direction == 0)   walk(matrix, visited, rows, cols, i, j+1, 0, 0);
      if (direction == 1)   walk(matrix, visited, rows, cols, i+1, j, 1, 0);
      if (direction == 2)   walk(matrix, visited, rows, cols, i, j-1, 2, 0);
      if (direction == 3)   walk(matrix, visited, rows, cols, i-1, j, 3, 0);
      return 0;
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
