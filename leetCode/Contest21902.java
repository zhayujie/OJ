/**
 * @author yujiezha
 * @description
 * @date 2020/12/13
 */
public class Contest21902 {
    public int minPartitions(String n) {
        char[] chars = n.toCharArray();
        int max = 0;
        for (char ch : chars) {
            if (ch - '0' > max) {
                max = ch - '0';
            }
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println(new Contest21902().minPartitions("32"));
        System.out.println(new Contest21902().minPartitions("82734"));
        System.out.println(new Contest21902().minPartitions("27346209830709182346"));
    }
}
