import java.util.*;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22101 {
    public boolean halvesAreAlike(String s) {
        char[] chs = new char[]{'a','e','i','o','u','A','E','I','O','U'};
        Set<Character> set = new HashSet<>();
        for (char ch : chs) {
            set.add(ch);
        }
        char[] str = s.toCharArray();
        int i = 0, j = s.length() / 2;
        int count1 = 0, count2 = 0;
        while (j > 0 && j < s.length()) {
            if (set.contains(str[i++])) {
                count1++;
            }
            if (set.contains(str[j++])) {
                count2++;
            }
        }
        return count1 == count2;
    }

    public static void main(String[] args) {
        String  s = "textbook";
        System.out.println(new Contest22101().halvesAreAlike(s));
    }
}
