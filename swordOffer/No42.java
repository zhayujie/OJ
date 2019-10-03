class FindContinuousSum {
    public int FindGreatestSumOfSubArray(int[] array) {
        int count = 0, max = Integer.MIN_VALUE;
        for (int ar: array) {
            count = count < 0 ? ar : (count + ar);
            max = Math.max(count, max);
        }
        return max;
    }

    public int FindByDP(int[] array) {
        int dp1 = array[0], max = dp1;
        for (int i = 1; i < array.length; i++) {
            int dp = Math.max(array[i], dp1+array[i]);
            dp1 = dp;
            max = Math.max(dp, max);
        }
        return max;
    }

    public static void main(String[] args) {
        int[] array = {6,-3,-2,7,-15,1,2,2};
        int max = new FindContinuousSum().FindByDP(array);
        System.out.println(max);
    }
}
