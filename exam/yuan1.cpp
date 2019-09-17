#include <iostream>
using namespace std;
#include <vector>

vector<int> res;

void walk(vector<vector<int> > matrix, int rows, int cols, int start) {
  int endRow = rows - start - 1;
  int endCol = cols - start - 1; 

  // 向下走
  for (int i = start; i <= endRow; i++) {
    res.push_back(matrix[i][start]);
  }
  if (endCol - 1 < start)  return;

  // 向右走
  for (int i = start+1; i <= endCol; i++) {
    res.push_back(matrix[endRow][i]);
  }
  if (start+1 > endRow)   return;

  // 向上走
  for (int i = endRow-1; i >= start; i--) {
    res.push_back(matrix[i][endCol]);
  }

  // 向左走
  for (int i = endCol-1; i > start; i--) {
    res.push_back(matrix[start][i]);
  }
}

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

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > matrix(n, vector<int>(m, 0));
  int t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
      // cout <<"matrix " << matrix[i][j] << endl;
    }
  }
  vector<int> vec = printMatrix(matrix);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size()-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }

  return 0;
}
