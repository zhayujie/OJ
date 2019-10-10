class RotateString {
    public String LeftRotateStringEasy(String str, int n) {
        int len = str.length();
        if (n >= len)    return str;
        return str.substring(n, len) + str.substring(0, n);
    }

    public String LeftRotateString(String str, int n) {
        int len = str.length();
        if (len <= n)   return str;
        char[] st = str.toCharArray();
        reverse(st, 0, len-1);
        reverse(st, 0, len-n-1);
        reverse(st, len-n, len-1);
        return new String(st);
    }

    private void reverse(char[] st, int lo, int hi) {
        int i = lo, j = hi;
        while (i < j) {
            char temp = st[i];
            st[i++] = st[j];
            st[j--] = temp;
        }
    }
}
