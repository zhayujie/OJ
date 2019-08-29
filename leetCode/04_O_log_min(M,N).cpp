#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      double median;
      // 两个有序数组的中位数 可以转化为第k小问题
      int len1 = nums1.size();
      int len2 = nums2.size();
      int len = len1 + len2;
      int lo1 = 0, hi1 = len1 - 1; 
      if (len1 > len2) {    // 使nums1为较短数组
        return findMedianSortedArrays(nums2, nums1);
      }
      int i = 0, j = 0;
      while (lo1 <= hi1) {
        i = (lo1 + hi1) / 2;
        j = (len - 1) / 2 - i;
        // 因为len2 > len1，所以 j 不可能取 len2
        if (i != len1 && j != 0 && nums1[i] < nums2[j-1]) {
          lo1 = i + 1;
        } 
        else if (i != 0 && nums2[j] < nums1[i-1]) {  
          hi1 = i - 1;
        } else {
          int left = 0, right = 0;   
          left = min(nums1[i], nums2[j]);       // 包括 i == 0 和 j == 0
          if (len % 2 != 0)    return left;

          if (j == len2 - 1 && nums2[j] <= nums1[i]) {
            right = nums1[i];
          } else if (i == len1 - 1 && nums1[i] <= nums2[j]) {
            right = nums2[j];
          } else {
            right = nums1[i] < nums2[j] ? min(nums1[i+1], nums2[j]) : min(nums1[i], nums2[j+1]);
          }
          cout << "left: " << left << " right: " << right << endl;

          return (left + right) * 1.0 / 2;
        }
      }
      // i == len1 时
      if (len1 != 0) {
        return len % 2 != 0 ? nums2[j-1] : (nums2[j-1] + nums2[j]) * 1.0 / 2;
      }
      else {    // nums1 为空
        return len % 2 != 0 ? nums2[(len-1)/2] : (nums2[(len-1)/2] + nums2[(len-1)/2+1]) * 1.0 / 2;
      }
    }
};

int main(void) {
  Solution soulution;
  int a1[] = {};
  int a2[] = {1};
  vector<int> nums1(a1, a1);
  vector<int> nums2(a2, a2 + 1);
  cout << soulution.findMedianSortedArrays(nums1, nums2) << endl; 

  return 0;   
}
