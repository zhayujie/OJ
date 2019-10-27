class Solution04 {
    int left = 0, right = 0, max = 0;

    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)   return "";

        for (int i = 0; i < s.length(); i++) {
            search(s, i, i);
            search(s, i, i+1);
        }
        return s.substring(left, right+1);
    }

    private void search(String s, int i, int j) {
        while (i >= 0 && j < s.length()) {
            if (s.charAt(i) == s.charAt(j)) {
                if (j - i + 1 > max) {
                    max = j - i + 1;
                    left = i;
                    right = j;
                }
            } else {
                break;
            }
            i--;
            j++;
        }
    }

    public static void main(String[] args) {
        Solution04 s = new Solution04();
        System.out.println(s.longestPalindrome("cbbd"));
    }
}