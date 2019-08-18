#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> res;
      double median;
      int len = nums1.size() + nums2.size();
      int count = 0;

      for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
        if (i >= nums1.size()) {
          res.push_back(nums2[j++]);
        } else if (j >= nums2.size()) {
          res.push_back(nums1[i++]);
        } else {
          if (nums1[i] < nums2[j]) {
            res.push_back(nums1[i++]);
          } else
          {
            res.push_back(nums2[j++]);
          }
        }
        count++;
        if (count == len / 2 + 1) {
          median = len % 2 == 0 ? ((res[len/2-1] + res[len/2]) * 1.0 / 2) : (res[len/2] * 1.0);
          break;
        }
      }
      
      // int len = res.size();
      // cout << "size: " << len << endl;
      // for (int k = 0; k < len; k++) {
      //   cout << res[k] << endl;
      // }

      // median = len % 2 == 0 ? ((res[len/2-1] + res[len/2]) * 1.0 / 2) : (res[len/2] * 1.0);

      return median;
    }
};

int main(void) {
  Solution soulution;
  int a1[] = {};
  int a2[] = {2, 3};
  vector<int> nums1(a1, a1 + 0);
  vector<int> nums2(a2, a2 + 2);
  cout << nums1.size() << nums2.size() << endl;
  cout << soulution.findMedianSortedArrays(nums1, nums2) << endl; 

  return 0;
}
