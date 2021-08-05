import java.util.HashMap;
import java.util.Map;

/**
 * @author yujiezha
 * @description
 * @date 2021/8/4
 */
public class No03_0804 {
    public int lengthOfLongestSubstring(String s) {
        int max = 0, start = 0;
        // 字符 - 上一次出现的索引
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            Integer index = map.get(ch);
            if (index != null && index >= start) {
                start = index + 1;
            } else {
                max = Math.max(max, (i-start)+1);
            }
            map.put(ch, i);
        }
        return max;
    }

    public static void main(String[] args) {
        int res = new No03_0804().lengthOfLongestSubstring("abcabcbb");
        System.out.println(res);
    }
}
