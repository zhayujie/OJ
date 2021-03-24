import java.util.ArrayList;
import java.util.List;

/**
 * @author yujiezha
 * @description 深度优先搜索+回溯的解法
 * @date 2020/12/16
 */
public class No017_v1 {
    private String[] nums = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private List<String> res = new ArrayList<>();
    private List<Character> chars = new ArrayList<>();


    public List<String> letterCombinations(String digits) {
        if (digits == null || "".equals(digits)) {
            return res;
        }
        letterCombinationsCore(digits);
        return res;
    }

    private void letterCombinationsCore(String digits) {
        if ("".equals(digits)) {
            res.add(createString(chars));
            return;
        }
        int index = digits.charAt(0) - '0';
        String str = nums[index];
        for (char ch : str.toCharArray()) {
            chars.add(ch);
            String digit = digits.length() == 1 ? "" : digits.substring(1);
            letterCombinationsCore(digit);
            // 回溯
            chars.remove(chars.size()-1);
        }
    }

    private String createString(List<Character> chars) {
        StringBuilder st = new StringBuilder();
        for (Character ch : chars) {
            st.append(ch);
        }
        return st.toString();
    }

    public static void main(String args[]) {
        System.out.println(new No017_v1().letterCombinations("23"));
    }
}
