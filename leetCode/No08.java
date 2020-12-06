import java.math.BigInteger;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/6
 */
class Solution08 {
    public int myAtoi(String s) {
        int val = 0;
        // 为1时是+号，为2时是-号
        int symbol = 0;
        // 是否有效 (以数字开头)
        boolean valid = false;

        // 跳过开头空格
        s = s.trim();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '-' && symbol == 0) {
                symbol = -1;
            } else if (ch == '+' && symbol == 0) {
                symbol = 1;
            } else if (ch >= '0' && ch <= '9') {
                if (symbol == 0) {
                    symbol = 1;
                }
                int num = ch - '0';
                // 判断是否将要溢出
                if (checkOverflow(val * symbol, num)) {
                    return symbol < 0 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                }
                val = val * 10 + num;
                valid = true;
            } else {
                if (!valid) {
                    return 0;
                }
                else {
                    break;
                }
            }
        }
        return symbol * val;
    }

    private boolean checkOverflow(int val, int num) {
        if (val < 0) {
            return val < Integer.MIN_VALUE / 10 || (val == Integer.MIN_VALUE / 10 && num > 8);
        }
        return val > Integer.MAX_VALUE / 10 || (val == Integer.MAX_VALUE / 10 && num > 7);
    }

    public static void main(String[] args) {
        System.out.println(new Solution08().myAtoi(" 213  213"));
        System.out.println(new Solution08().myAtoi("1+123"));
        System.out.println(new Solution08().myAtoi(" 00-42"));
        // 大于Long.MAX_VALUE
        System.out.println(new Solution08().myAtoi("9223372036854775808"));
    }
}
