import java.util.concurrent.atomic.AtomicInteger;

class Str2Int {
    public int StrToInt(String str) {
        if (str == null || str.length() == 0)  return 0;
        char[] st = str.toCharArray();
        long sum = 0, symbol = 1;
        for (int i = 0; i < st.length; i++) {
            if (i == 0 && st.length > 1 && (st[i] == '+' || st[i] == '-')) {
                if (st[i] == '-')   symbol = -1;
                continue;
            }
            if (st[i] < '0' || st[i] > '9') {
                return 0;
            }
            sum = sum * 10 + (st[i] - '0');
        }
        sum *= symbol;
        if (sum > 0x7fffffff || sum < 0x80000000) {
            return 0;
        }
        return (int) sum;
    }

    public static void main(String[] args) {
        Object obj = new Object();
        System.out.println(new Str2Int().StrToInt("-2147483648"));
    }
}
