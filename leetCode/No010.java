/**
 * @author zhayujie
 * @description
 * @date 2020/12/12
 */
public class No010 {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) {
            return false;
        }
        return isMatch(s, p, 0, 0);
    }

    private boolean isMatch(String s, String p, int i, int j) {
        if (j >= p.length()) {
            // 当表达式结束了，如果字符串没结束，则说明不匹配
            return i == s.length();
        }
        if (isNextStar(p, j)) {
            // 正则表达式的下一个字符是*，有两种选择
            // 1.如果当前字符匹配，则表达式可以选择原地不动，字符串后移，即匹配1次或多次
            // 2.不管是否匹配，表达式都可以选择直接跳过，即匹配0次
            return (comp(s, p, i, j) && isMatch(s, p, i+1, j)) || isMatch(s, p, i, j+2);
        } else {
            // 下一个字符不是*
            // 如果当前字符匹配，则字符串和表达式均后移一位
            return comp(s, p, i, j) && isMatch(s, p, i+1, j+1);
        }
    }

    // 比较两个字符是否相等
    private boolean comp(String s, String p, int i, int j) {
        return i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
    }

    // 判断表达式下一个字符是否是*
    private boolean isNextStar(String p, int j) {
        return j < p.length()-1 && p.charAt(j+1) == '*';
    }

    public static void main(String[] args) {
        System.out.println(new No010_v0().isMatch("aa", "a"));
        System.out.println(new No010_v0().isMatch("aa", "a*"));
        System.out.println(new No010_v0().isMatch("ab", ".*"));
        System.out.println(new No010_v0().isMatch("aab", "c*a*b"));
        System.out.println(new No010_v0().isMatch("mississippi", "mis*is*p*."));

        System.out.println(new No010_v0().isMatch("a", "ab*"));
        System.out.println(new No010_v0().isMatch("a", "ab*t*c*"));
        System.out.println(new No010_v0().isMatch("bbbba", ".*a*a"));
    }
}
