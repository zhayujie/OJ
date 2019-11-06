import javax.xml.transform.Source;

class Solution06 {
    public String convert(String s, int numRows) {
        if (s == null || s.equals("") || numRows == 1)  return s;

        int len = s.length();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < numRows; i++) {
            int index = i;
            for (int count = 1, k = 0; index < len; count++) {
                k = count * (numRows - 1);
                if (k > index) {
                    sb.append(s.charAt(index));
                    index = (k - index) + k;
                }
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution06 solution = new Solution06();
        System.out.println(solution.convert("AB", 1));
    }
}