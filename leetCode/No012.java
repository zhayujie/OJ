/**
 * @author zhayujie
 * @description
 * @date 2020/12/14
 */
public class No012 {
    public String intToRoman(int num) {
        String str[] = new String[]{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int val[] = new int[]{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            int index = find(num, val);
            num -= val[index];
            sb.append(str[index]);
        }
        return sb.toString();
    }

    private int find(int num, int val[]) {
        // 二分法
        int i = 0, j = val.length - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (num < val[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return j;
    }

    public static void main(String[] args) {
        System.out.println(new No012().intToRoman(3));
        System.out.println(new No012().intToRoman(4));
        System.out.println(new No012().intToRoman(9));
        System.out.println(new No012().intToRoman(58));
        System.out.println(new No012().intToRoman(1994));
    }
}
