/**
 * @author zhayujie
 * @description
 * @date 2020/12/12
 */
public class No010_v0 {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) {
            return false;
        }
        return isMatch(s, p, 0, 0);
    }

    private boolean isMatch(String s, String p, int i, int j) {
        if (i == s.length()) {
            if (j == p.length()) {
                return true;
            }
            if (isNextStar(p, j)) {
                return isMatch(s, p, i, j+2);
            }
        }
        if (i > s.length() - 1 || j > p.length() - 1) {
            return false;
        }
        // 先判断字符是否相等，再判断是否有*号
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
            if (isNextStar(p, j)) {
                return isMatch(s, p,i+1, j) || isMatch(s, p, i, j+2);
            } else {
                return isMatch(s, p, i+1, j+1);
            }
        } else {
            if (isNextStar(p, j)) {
                return isMatch(s, p, i, j+2);
            } else {
                return false;
            }
        }
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
