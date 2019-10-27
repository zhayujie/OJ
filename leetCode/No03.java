class Solution03 {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.equals(""))  return 0;
        int len = s.length();
        int max = 0, lo = 0, hi = 0;
        int[] index = new int[128];
        for (int i = 0; i < index.length; i++) {
            index[i] = -1;
        }

        while (hi < len) {
            char ch = s.charAt(hi);
            if (index[ch] >= lo) {
                lo = index[ch] + 1;
            }
            max = Math.max(max, hi-lo+1);
            // 该字符最后一次出现的索引
            index[ch] = hi;
            hi++;
        }
        return max;
    }
}