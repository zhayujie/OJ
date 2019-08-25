#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len1 = nums1.size();
      int len2 = nums2.size();
      int left = (len1 + len2 + 1) / 2;
      int right = (len1 + len2 + 2) / 2;
      // 将总长度为偶数和奇数的两种情况合并
      return (findKth(nums1, 0, len1-1, nums2, 0, len2-1, left) + findKth(nums1, 0, len1-1, nums2, 0, len2-1, right)) * 1.0 / 2;
    }

    int findKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
      int len1 = end1 - start1 + 1;
      int len2 = end2 - start2 + 1;
      // 保证len1 < len2, 如果有空数组, 一定是len1
      if (len1 > len2)    return findKth(nums2, start2, end2, nums1, start1, end1, k);
      if (len1 == 0)      return nums2[start2 + k - 1];

      if (k == 1)         return min(nums1[start1], nums2[start2]);

      int i = start1 + min(len1, k / 2) - 1;
      int j = start2 + min(len2, k / 2) - 1;
      if (nums1[i] > nums2[j]) {
        return findKth(nums1, start1, end1, nums2, j+1, end2, k-(j-start2+1));
      } else {
        return findKth(nums1, i+1, end1, nums2, start2, end2, k-(i-start1+1));
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
