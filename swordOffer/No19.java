class MatchReg {
    public boolean match(char[] str, char[] pattern)
    {
        return matchCore(str, pattern, 0, 0);
    }
    private boolean matchCore(char[] str, char[] pattern, int i, int j) {
        int len1 = str.length,  len2 = pattern.length;
        if (i == len1 && j == len2)     return true;
        if (j == len2)     return false;        // 字符串可以用完，模式不可以用完
        if (i > len1)      return false;
        if (j < len2 - 1 && pattern[j+1] == '*') {
            if (i == len1 || (pattern[j] == '.' || pattern[j] == str[i])) {
                return matchCore(str, pattern, i + 1, j) || matchCore(str, pattern, i, j + 2);
            } else {
                return matchCore(str, pattern, i, j+2);
            }
        } else {
            if (i < len1 && (str[i] == pattern[j] || pattern[j] == '.')) {
                return matchCore(str, pattern, i+1, j+1);
            } else {
                return false;
            }
        }
    }


    public static void main(String[] args) {
        System.out.println(new MatchReg().match(new char[]{}, new char[]{'c', '*'}));
    }

}
