/**
 * @author zhayujie
 * @description
 * @date 2021/8/8
 */
public class Contest25301 {
    public boolean isPrefixString(String s, String[] words) {
        if (s == null) {
            return false;
        }
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            sb.append(word);
            if (s.equals(sb.toString())) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

    }
}
