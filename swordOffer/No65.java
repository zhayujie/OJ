class AddWithOutSymbol {
    public int Add(int num1, int num2) {
        int sum = 0, proBit = 0;
        do {
            sum = num1 ^ num2;
            proBit = (num1 & num2) << 1;
            num1 = sum;
            num2 = proBit;
        } while (proBit != 0);
        return sum;
    }

    public static void main(String[] args) {
        int n = new AddWithOutSymbol().Add(-1, 2);
        System.out.println(n);
        char a = 'a';
        char b = 'c';
        System.out.println(-2147483648 == 0x80000000);
    }
}
