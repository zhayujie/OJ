import java.util.LinkedList;

/**
 * @author zhayujie
 * @description
 * @date 2021/8/8
 */
public class Contest25303 {
//    public int minSwaps(String s) {
//        int l = 0, r = 0, count = 0;
//        LinkedList<Character> stack = new LinkedList<>();
//        for (int i = 0; i < s.length(); i++) {
//            char cur = s.charAt(i);
//            if (cur == '[') {
//                stack.push(cur);
//                continue;
//            }
//            Character ch = stack.peekLast();
//            if (ch != null && ch == '[') {
//                stack.pop();
//                continue;
//            }
//            stack.push('[');
//            count++;
//        }
//        return count;
//    }
public int minSwaps(String s) {
    int l = 0, r = 0, count = 0;
    LinkedList<Character> stack = new LinkedList<>();
    for (int i = 0; i < s.length(); i++) {
        char cur = s.charAt(i);
        if (cur == '[') {
            stack.push(cur);
            continue;
        }
        Character ch = stack.peekLast();
        if (ch != null && ch == '[') {
            stack.pop();
            continue;
        }
        stack.push('[');
        count++;
    }
    return count;
}

    public static void main(String[] args) {
    LinkedList
        System.out.println(new Contest25303().minSwaps("]]][[["));
    }
}
