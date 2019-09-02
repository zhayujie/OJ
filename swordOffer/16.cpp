#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    1.将所有偶数移动到数组末尾
    void reOrderArray(vector<int> &array) {
      int len = array.size();
      vector<int>::iterator iter = array.begin();    
      for (int i = 0, k = 0; i < len; i++) {
        int val = array[k];
        if ((val & 1) == 0) {
          array.erase(iter+k);
          array.push_back(val);
        } else {
          k++;
        }
      }
    }
    */
    // 2.类似于冒泡排序，偶数不断移动到数组尾部
    void reOrderArray(vector<int> &array) {
      int len = array.size();
      for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
          if (!(array[j] & 1) && (array[j+1] & 1)) {
            int temp = array[j+1];
            array[j+1] = array[j];
            array[j] = temp;
          }
        }
      }
    }
};

int main(void) {
  Solution soulution;
  return 0;
}
