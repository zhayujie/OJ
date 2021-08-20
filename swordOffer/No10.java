/**
 * @author yujiezha
 * @description
 * @date 2021/8/19
 */
public class No10 {
    public int numWays(int n) {
        if (n == 0) {
            return 1;
        }
        if (n <= 2) {
            return n;
        }
        // dp[n] = dp[n-1] + dp[n-2]
        int dp1 = 1;
        int dp2 = 2;
        int dp = 0;
        for (int k = 3; k <= n; k++) {
            dp = (dp1 + dp2) % 1000000007;
            dp1 = dp2;
            dp2 = dp;
        }
        return dp;
    }

    public static void main(String[] args) {
        System.out.println(new No10().numWays(46));
    }
}
