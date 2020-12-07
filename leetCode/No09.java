/**
 * @author zhayujie
 * @description 回文数
 * @date 2020/12/7
 */
class Solution09 {
    public boolean isPalindrome(int x) {
        String str = String.valueOf(x);
        // 双指针从首位往中间比较
        for (int i = 0, j = str.length() - 1; i <= j; i++, j--) {
            if (str.charAt(i) != str.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new Solution09().isPalindrome(121));
        System.out.println(new Solution09().isPalindrome(-121));
        System.out.println(new Solution09().isPalindrome(10));
    }
}
