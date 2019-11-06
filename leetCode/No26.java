class Solution26 {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len <= 1)   return len;

        int i = 0;
        for (int j = 1; j < len; j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }

    public static void main(String[] args) {
        int[] a = {1, 1};
        int res = new Solution26().removeDuplicates(a);
        System.out.println(res);

        for (int i = 0; i < res; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
