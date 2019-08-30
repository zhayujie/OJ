#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
      if (rotateArray.size() == 0)  return 0;

      // 1.顺序查找 O(N)
      // for (int i = 0; i < rotateArray.size(); i++) {
      //   if (rotateArray[i] < rotateArray[0]) {
      //     return rotateArray[i];
      //   }
      // }
      // return rotateArray[0];     

      // 2.二分法O(logN)
      int lo = 1, hi = rotateArray.size() - 1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (rotateArray[mid] < rotateArray[hi]) {
          // 最小值在mid前半部分，包括mid
          hi = mid;
        } else if (rotateArray[mid] > rotateArray[hi]) {
          // 最小值在mid后半部分，不包括mid
          lo = mid + 1;
        } else {
          // 遇到重复数字，不确定在前还是后，所以把后指针前移
          hi--;
        }
      }
      return rotateArray[lo];
    }
};

int main(void) {
  Solution soulution;
  int a[] = {3,3,3,1,2};
  vector<int> vec(a, a+4);
  int res = soulution.minNumberInRotateArray(vec);
  cout << res << endl;

  return 0;
}
