class Solution07 {
    public int reverse(int x) {
        long sum = 0;
        while (x != 0) {
            int num = x % 10;
            x /= 10;
            sum = sum * 10 + num;
            if (sum > 0x7fffffff || sum < 0x80000000) return 0;
        }
        return (int) sum;
    }

    public static void main(String[] args) {
        Solution07 s = new Solution07();
        System.out.println(1534236469);
        System.out.println(s.reverse(1534236469));
    }
}