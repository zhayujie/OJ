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
      // cout << "新的一轮" << endl;
      while (lo1 <= hi1) {
        int mid1 = (lo1 + hi1) / 2;
        int lo2 = 0, hi2 = len2 - 1;
        while (lo2 <= hi2) {
          int mid2 = (lo2 + hi2) / 2;
          if (nums1[mid1] == nums2[mid2]) {
            lo2 = mid2;
            break;
          }
          else if (nums1[mid1] < nums2[mid2]) {
            hi2 = mid2 - 1;
          } else
          {
            lo2 = mid2 + 1;
          }
        }
        int k = (len - 1) / 2;
        if (mid1 + lo2 == k) {
          cout << "mid1: " << mid1 << " lo2: " << lo2 << endl;
          if (len % 2 != 0) {
            median = nums1[mid1];
          } else {
            int nextVal = 0;
            if (len2 == 0 || lo2 >= len2)   nextVal = nums1[mid1+1]; 
            else if (mid1 == len1 - 1)      nextVal = nums2[lo2];
            else                            nextVal = min(nums1[mid1+1], nums2[lo2]);
            median = (nums1[mid1] + nextVal) * 1.0 / 2;
          }
          return median;
        } else if (lo2 < len2 && nums1[mid1] == nums2[lo2]) {
          cout << "mid1: " << mid1 << " lo2: " << lo2 << endl;
          if (nums2[k-mid1] == nums2[lo2] || (k-mid1-1 >= 0  && nums2[k-mid1-1] == nums2[lo2])) {
            if (len % 2 != 0)               median = nums1[mid1] * 1.0;
            else {
              int nextVal = 0;
              if (mid1 == len1 - 1)                     nextVal = nums2[lo2];
              else if (nums2[k-mid1] == nums2[lo2])     nextVal = min(nums1[mid1+1], nums2[lo2]);
              else if (k-mid1-1 >= 0  && nums2[k-mid1-1] == nums2[lo2])   nextVal = min(nums1[mid1+1], nums2[lo2+1]);
              median = (nums1[mid1] + nextVal) * 1.0 / 2;
            }                             
            return median;
          }
        }
        if  (mid1 + lo2 < k) {
          lo1 = mid1 + 1;
        } else if (mid1 + lo2 > k) {
          hi1 = mid1 - 1;
        }
      }
      return findMedianSortedArrays(nums2, nums1);
    }
};

int main(void) {
  Solution soulution;
  int a1[] = {1};
  int a2[] = {2, 3, 4};
  vector<int> nums1(a1, a1 + 1);
  vector<int> nums2(a2, a2 + 3);
  cout << soulution.findMedianSortedArrays(nums1, nums2) << endl; 

  return 0;
}
