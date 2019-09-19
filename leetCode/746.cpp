#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int size = cost.size();
    //     int dp[size];
    //     memset(dp, 0, sizeof(dp));
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];
    //     for (int i = 2; i < size; i++) {
    //         // 到达该台阶最少的花费
    //         dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
    //     }
    //     return min(dp[size-2], dp[size-1]);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int dp1 = cost[0];      // 上上一个
        int dp2 = cost[1];      // 上一个
        for (int i = 2; i < size; i++) {
            int tmp = dp2;
            dp2 = min(dp2, dp1) + cost[i];
            dp1 = tmp;
        }
        return min(dp1, dp2);
    }
};

int main(void) {
    int t[4] = {0, 0, 1, 1};
    vector<int> vec(t, t+4);
    Solution solution;
    cout << solution.minCostClimbingStairs(vec) << endl;
}
