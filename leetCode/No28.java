class No28 {
    public int strStr(String haystack, String needle) {
        if (needle == null || "".equals(needle)) {
            return 0;
        }
        int i = 0, j = 0, start = 0;
        while (i < haystack.length()) {
            start = i;
            while (j < needle.length()) {
                if (i >= haystack.length()) {
                    return -1;
                }
                if (haystack.charAt(i) == needle.charAt(j)) {
                    i++;
                    j++;
                } else {
                    i = start + 1;
                    j = 0;
                    break;
                }
            }
            if (j == needle.length()) {
                return start;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(new No28().strStr("tsff", "ff"));
    }
}
