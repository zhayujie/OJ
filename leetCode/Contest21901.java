/**
 * @author yujiezha
 * @description
 * @date 2020/12/13
 */
public class Contest21901 {
    public int numberOfMatches(int n) {
        int count = 0;
        while (n > 1) {
            count += n / 2;
            n = n / 2 + n % 2;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(new Contest21901().numberOfMatches(7));
        System.out.println(new Contest21901().numberOfMatches(14));
    }
}
