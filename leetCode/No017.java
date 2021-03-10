import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author yujiezha
 * @description 组合的循环解法
 * @date 2020/12/16
 */
public class No017 {
    public List<String> letterCombinations(String digits) {
        String[] nums = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> prevList = new ArrayList<>();
        for (char ch : digits.toCharArray()) {
            String str = nums[ch - '0'];
            List<String> newList = new ArrayList<>();
            for (char c : str.toCharArray()) {
                if (prevList.size() == 0) {
                    newList.add(""+c);
                    continue;
                }
                for (String prev : prevList) {
                    newList.add(prev + c);
                }
            }
            prevList = newList;
        }
        return prevList;
    }

    public static void main(String args[]) {
        System.out.println(new No017().letterCombinations(""));
    }
}
