package exam;

import java.util.LinkedList;

public class EncodeString {
    public String encode(String st) {
        int timeIndex = 0;
        int times = 0;
        int intFlag = 0;
        LinkedList<Character> strStack = new LinkedList<>();
        LinkedList<Integer> nums = new LinkedList<>();
        StringBuilder finalRes = new StringBuilder();

        for (int i = 0; i < st.length(); i++) {
            char ch = st.charAt(i);
            if (ch >= '0' && ch <= '9') {
                if (intFlag == 0) {
                    timeIndex = i;
                    intFlag = 1;
                }
            } else if (ch == '[') {
                strStack.addLast(ch);
                times = Integer.parseInt(st.substring(timeIndex, i));
                System.out.println(times);
                nums.addLast(times);
                intFlag = 0;
            } else if (ch == ']') {
                StringBuilder sb = new StringBuilder();
                while (true) {
                    char c = strStack.removeLast();
                    if (c == '[') {
                        break;
                    }
                    sb.append(c);
                }
                String temp = sb.toString();
                int time = nums.removeLast();
                for (int j = 0; j < time; j++) {
                    for (int k = temp.length()-1; k >= 0; k--) {
                        strStack.addLast(temp.charAt(k));
                    }
                }
            } else {
                strStack.addLast(ch);
            }
        }

        while (!strStack.isEmpty()) {
            finalRes.append(strStack.removeFirst());
        }

        return finalRes.toString();
    }

    public static void main(String[] args) {
        String st = "22[ab]";
        String res = new EncodeString().encode(st);
        System.out.println(res);
    }
}
