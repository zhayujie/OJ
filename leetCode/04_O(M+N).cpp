#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      double median;
      int len1 = nums1.size();
      int len2 = nums2.size();
      int len = len1 + len2;
      int last = 0, now = 0, count = 0;

      for (int i = 0, j = 0; i < len1 || j < len2;) {
        last = now;
        if (i < len1 && j < len2) {
          now = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        } else {
          now = i >= len1 ? nums2[j++] : nums1[i++];
        }
        count++;
        if (count == len / 2 + 1) {
          median = len % 2 != 0 ? now : ((now + last) * 1.0 / 2); 
          break;
        }
      }
      return median;
    }
};

int main(void) {
  Solution soulution;
  int a1[] = {};
  int a2[] = {3, 4};
  vector<int> nums1(a1, a1);
  vector<int> nums2(a2, a2 + 2);
  cout << soulution.findMedianSortedArrays(nums1, nums2) << endl; 

  return 0;
}
