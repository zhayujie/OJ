class No26 {
    public int removeDuplicates(int[] nums) {
        int i = 1, k = 0;
        while (i < nums.length) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
            i++;
        }
        return k + 1;
    }

    public static void main(String[] args) {
        int[] a = {0,0,1,1,1,2,2,3,3,4};
        int res = new No26().removeDuplicates(a);
        System.out.println(res);
    }
}
