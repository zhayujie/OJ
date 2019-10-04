class NumberOf1 {
    public int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += getCount(i);
        }
        return count;
    }
    private int getCount(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 10 == 1) {
                count++;
            }
            n /= 10;
        }
        return count;
    }
}
