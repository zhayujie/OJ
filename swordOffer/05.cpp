#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowNum = array.size();
        int colNum = array[0].size();
        for (int row = rowNum - 1, col = 0; row >= 0 && col < colNum;) {
          // cout << row << " "<< col << endl;
          if (array[row][col] > target) {
            row--;
          } else if (array[row][col] < target) {
            col++;
          } else {
            return true;
          }
        }
        return false;
    }
};

int main(void) {
  Solution soulution;
  vector<vector<int> > vecs(2, vector<int>(2, 0));
  vecs[0][0] = 1;
  vecs[0][1] = 2;
  vecs[1][0] = 3;
  vecs[1][1] = 5;
  cout << soulution.Find(3, vecs) << endl; 

  return 0;
}
