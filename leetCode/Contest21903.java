/**
 * @author yujiezha
 * @description
 * @date 2020/12/13
 */
public class Contest21903 {
    public int stoneGameVII(int[] stones) {
        int len = stones.length;
        int[][]dp = new int[len][len];
        int[]sum = new int[len];

        sum[0] = stones[0];
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i-1] + stones[i];
        }
        for (int i = len-2; i >= 0; i--) {
            for (int j = 1; j < len; j++) {
                if (i < j) {
                    int sum1 = sum[j-1] - (i > 0 ? sum[i-1] : 0);
                    int sum2 = sum[j] - sum[i];
                    dp[i][j] = Math.max(sum1 - dp[i][j-1], sum2 - dp[i+1][j]);
                }
            }
        }
        return dp[0][len-1];
    }

    public static void main(String[] args) {
        int[] stones = {7,90,5,1,100,10,10,2};
        System.out.println(new Contest21903().stoneGameVII(stones));
    }
}
