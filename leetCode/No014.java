/**
 * @author yujiezha
 * @description
 * @date 2020/12/15
 */
public class No014 {
    public String longestCommonPrefix(String[] strs) {
        int i;
        if (strs.length <= 0 || strs[0].length() <= 0) {
            return "";
        }
        char[] firstStr = strs[0].toCharArray();
        for (i = 0; i < firstStr.length; i++) {
            boolean flag = true;
            char ch = firstStr[i];
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != ch) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return i > 0 ? strs[0].substring(0, i) : "";
    }

    public static void main(String[] args) {
        String[] strList = new String[]{"flower","flow","flight"};
        String[] strList2 = new String[]{"dog","racecar","car"};
        System.out.println(new No014().longestCommonPrefix(strList));
        System.out.println(new No014().longestCommonPrefix(strList2));
    }
}
