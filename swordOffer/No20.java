class NumericJudge {
    // "[+/-]123[E/e][+/-]123"
    public boolean isNumeric(char[] str) {
        boolean hasPoint = false;
        for (int i = 0; i < str.length; i++) {
            char ch = str[i];
            if (i == 0 && (ch == '+' || ch == '-')) {
                continue;
            }
            else if (ch == 'E' || ch == 'e') {
                if (i == 0 || !isDigit((str[i-1]))) {
                    return false;
                } else {
                    return isInt(str, i+1, str.length-1);
                }
            }
            else if (ch == '.') {
                if (i != 0 && (!isDigit(str[i-1]) && str[i-1] != '+' && str[i-1] != '-') || hasPoint) {
                    return false;
                } else {
                    hasPoint = true;
                }
            } else {
                if (!isDigit(ch)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isDigit(char ch) {
        return  ch >= '0' && ch <= '9';
    }

    private boolean isInt(char[] str, int lo, int hi) {
        if (lo > hi)        return false;
        if (str[lo] == '+' || str[lo] == '-') {
            lo++;
        }
        if (lo > hi)   return false;
        for (int i = lo; i < hi; i++) {
            if (!isDigit(str[i])) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        String st = "123.4e+5";
        System.out.println(new NumericJudge().isNumeric(st.toCharArray()));
    }
}
