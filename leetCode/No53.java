class No53 {
    public int maxSubArray(int[] nums) {
        if (nums == null) {
            return 0;
        }
        // dp[i] = dp[i-1] < 0 ? a[i] : dp[i-1] + a[i]   末尾为i的数组的最大和
        int prev = nums[0];
        int max = prev;
        for (int i = 1; i < nums.length; i++) {
              prev = prev < 0 ? nums[i] : (nums[i] + prev);
              max = Math.max(max, prev);
        }
        return max;
    }

    public static void main(String[] args) {
    }
}
