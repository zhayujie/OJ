import java.util.ArrayList;
import java.util.Comparator;

class MinNumber {
    public String PrintMinNumber(int [] numbers) {
        ArrayList<String> list = new ArrayList<>();
        for (int ar : numbers) {
            list.add(String.valueOf(ar));
        }
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
//                int i;
//                String sub = "";
//                for (i = 0; i < o1.length() && i < o2.length(); i++) {
//                    if (o1.charAt(i) < o2.charAt(i)) {
//                        return -1;
//                    } else if (o1.charAt(i) > o2.charAt(i)) {
//                        return 1;
//                    }
//                }
//                if (o1.length() == o2.length()) {
//                    return 0;
//                } else if (o1.length() > o2.length()) {
//                    sub = o1.substring(i);
//                    return compare(sub, o2);
//                } else {
//                    sub = o2.substring(i);
//                    return compare(o1, sub);
//                }
                String m = o1 + "" + o2;
                String n = o2 + "" + o1;
                return m.compareTo(n);
            }
        });
        StringBuilder sb = new StringBuilder();
        for (String st : list) {
            sb.append(st);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        int[] nums = {3, 32, 321};
        System.out.println(new MinNumber().PrintMinNumber(nums));
    }
}
