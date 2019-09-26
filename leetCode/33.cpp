#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) {
                return true;
            }
            // 三者相等时，无法确定target在左侧还是右侧，故继续缩小范围
            if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            // mid之前是有序的  (不加等号会报错 如[3,1], 当lo==mid时)
            else if (nums[mid] >= nums[lo]) {
                // 在前半段
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            } 
            // mid之后是有序
            else { 
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(void) {
    Solution s;
    int a[] = {3, 1};
    vector<int> vec(a, a+2);
    cout << s.search(vec, 1) << endl;
}